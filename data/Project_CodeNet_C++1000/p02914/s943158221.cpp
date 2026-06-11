/**
 * 链接：https://atcoder.jp/contests/abc141/tasks/abc141_f
 *
 *
 * 题意：给出长度为ｎ的数组，将数组拆分成两个数组a,b，最大化（a数组每个元素的异或＋ｂ数组每个元素的异或）
 *
 * 线性基
 *
 */


#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;
typedef long long       ll;
const long long      maxn = 3e5 + 7;
const long long      mod = 1e9 + 7;

ll anss = 0,a[maxn];

struct Linear_Basis {
    ll b[63], nb[63], tot; //b为线性基  nb用来求第K小异或值 tot为nb元素个数
    bool flag = false;

    void Init() {    //初始化
        tot = 0;
        flag = false;
        memset(b, 0, sizeof(b));
        memset(nb, 0, sizeof(nb));
    }

    void Ins(ll x) { //插入
        for (long long      i = 62; i >= 0; i--) {
            if ((!(anss&1ll<<i))&&(x & (1ll << i))) {//正常模板不需要!(anss&1ll<<i))&&
                if (!b[i]) {
                    b[i] = x;
                    return;
                }
                x ^= b[i];
            }
        }

        for (long long      i = 62; i >= 0; i--) {//常规题不需要这段
            if (!(anss&1ll<<i)&&(x & (1ll << i))) {
                if (!b[i]) {
                    b[i] = x;
                    return;
                }
                x ^= b[i];
            }
        }

        flag = true;
        return;
    }

    bool Fin(ll x) { //验证存在性
        if (x == 0 && b[0])return 1;
        for (long long      i = 62; i >= 1; i--) {
            long long      j = i - 1;
            if (x & (1 << j)) {
                x ^= b[i];
                if (!x)return 1;
            }
        }
        return 0;
    }

    ll Max(ll x) {   //求最大值
        ll res = x;
        for (long long      i = 62; i >= 0; i--) {
            res = max(res, res ^ b[i]);
        }
        return res;
    }

    ll Min(ll x) {   //求最小值
        ll res = x;
        for (long long      i = 0; i <= 62; i++) {
            if (b[i])res ^= b[i];
        }
        return res;
    }

    ll Rebuild() {   //第K大
        for (long long      i = 62; i >= 0; i--) {
            if (b[i] == 0)continue;
            for (long long      j = i - 1; j >= 0; j--) {
                if (b[j] == 0)continue;
                if (b[i] & (1ll << j))b[i] ^= b[j];
            }
        }
        for (long long      i = 0; i <= 62; i++) {
            if (b[i])nb[tot++] = b[i];
        }
    }

    ll Kth_Max(ll k) {
        if (flag)k--;  //???
        ll res = 0;
        if (k == 0)return 0;
        if (k >= (1ll << tot))return -1ll;
        for (long long      i = 62; i >= 0; i--) {
            if (k & (1ll << i))res ^= nb[i];
        }
        return res;
    }
} LB;



int   main() {
    long long      t;
    long long      tt = 1;
    long long      n, q;
    cin>>n;
    LB.Init();

    for (long long      i = 0; i < n; i++) {
        cin>>a[i];
        anss ^= a[i];
    }
    for (long long      i = 0; i < n; i++) {
        LB.Ins(a[i]);
    }
    LB.Rebuild();
    ll k;
//    scanf("%lld", &k);
    ll now=LB.Max(0);
    ll ret=now+(now^anss);

    ll tmp=0;

    for(ll i=62;i>=0;i--){
        if(!(anss&(1ll<<i)&&!(tmp&1ll<<i))) tmp^=LB.b[i];
    }for(ll i=62;i>=0;i--){
        if((anss&(1ll<<i)&&(tmp&1ll<<i))) tmp^=LB.b[i];
    }

    cout<<tmp+(tmp^anss)<<endl;
    return 0;

//    now=max(now,tmp+(anss^tmp));
//
//    ll xx=1ll<<LB.tot;
//    cout<<xx<<endl;
//    for(ll kk=xx;kk>=max(0ll,xx-1000000ll);kk--){
//        now=LB.Kth_Max(kk);
//        ret=max(ret,(now+(now^anss)));
//        else break;
//    }
//    cout<<ret<<endl;
    return 0;
}


