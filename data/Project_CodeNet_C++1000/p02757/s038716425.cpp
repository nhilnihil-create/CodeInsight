#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main(){
    int64_t n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    Re(s);
    int64_t num=0;
    int64_t ans=0;
    vector<int> a(n+1);
    a[0]=0;
    //p=2,5の時は10が影響にはいってきちゃうから、特別なやり方を考える
    if(p==2){
        rep(i,n){
            if((s[i]-'0')%2==0){
                ans += (n-i);
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    if(p==5){
        rep(i,n){
            if((s[i]-'0')%5==0){
                ans += n-i;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    rep(i,n){
        num=num+modpow(10,i,p)*(s[i]-'0')%p;
        num%=p;
        a[i+1]=num;
        //cout<<num<<endl;
    }
    vector<int64_t> cnt(p);
    rep(i,n+1){
        cnt[a[i]]++;
    }
    rep(i,p){
        ans += cnt[i]*(cnt[i]-1)/2;
    }
    cout<<ans<<endl;
}