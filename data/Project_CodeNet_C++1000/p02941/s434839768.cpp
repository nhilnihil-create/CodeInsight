//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;
const int BUF = (int)1e7;

int q[BUF];
int qh = 0, qt = 0;
int n;
int a[N], b[N];
bool eq[N];

inline int prv(int i){
    ret i ? i - 1 : (n - 1);
}

inline int nxt(int i){
    ret i + 1 == n ? 0 : (i + 1);
}

inline void push(int x){
    q[qt++] = x;
}

inline void upd(int i){
    int l = prv(i), r = nxt(i);
    int pl = prv(l), nr = nxt(r);
    if(b[l] > b[pl] + b[i] && !eq[l])
        q[qt++] = l;
    if(b[r] > b[nr] + b[i] && !eq[r])
        q[qt++] = r;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    F(i, 0, n)
        cin >> a[i];
    F(i, 0, n)
        cin >> b[i];
    F(i, 0, n){
        if(a[i] == b[i]){
            eq[i] = 1;
            cont;
        }
        if(a[i] > b[i]){
            cout << -1;
            ret 0;
        }
        if(b[i] > b[prv(i)] + b[nxt(i)])
            push(i);
    }
    ll ans = 0;
    while(qh < qt){
        int i = q[qh++];
        int sum = b[prv(i)] + b[nxt(i)];
        if(sum >= b[i])cont;
        if(a[i] >= sum){
            if(a[i]%sum == b[i]%sum){
                ans += (b[i] - a[i])/sum;
                b[i] = a[i];
                eq[i] = 1;
            }
            else{
                cout << -1;
                ret 0;
            }
            upd(i);
        }
        else{
            ans += b[i]/sum;
            b[i] %= sum;
            if(b[i] < a[i]){cout << -1; ret 0;}
            if(b[i] == a[i])eq[i] = 1;
            upd(i);
        }
    }
    F(i, 0, n)
        if(a[i] != b[i])
            ans = -1;
    cout << ans;
    return 0;
}
