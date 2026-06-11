#include "bits/stdc++.h"
using namespace std;
#define all(v) (v).begin(), (v).end()
#define io ios::sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rson rt << 1 | 1, mid + 1, r
#define lson rt << 1, l, mid
#define lll __int128
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eps 1e-12
#define int long long
const int mod = 1e9 + 7;
inline int ksm(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1)
            ans = ans * a % mod;
    return ans;
}
char s[200];
int cal(int x){
    return x/2;
}
signed main()
{
    io;
    vector<int> v;
    cin>>s+1; int k;cin>>k;
    int n=strlen(s+1);
    rep(i,1,n){
        int p=i;while(p+1<=n&&s[p+1]==s[p])p++;
        v.pb(p-i+1);
        i=p;
    }
    if(v.size() == 1){
        cout<<cal(k*v[0])<<endl;
    }
    else {
        if(s[1]==s[n]){
            int t=cal(v[0]);
            t += cal(v[v.size()-1]);
            t += (k-1)*cal(v[0]+v[v.size()-1]);
            for(int i=1;i<v.size()-1;i++){
                t += cal(v[i])*k;
            }
            cout<<t<<endl;
        }
        else {
            int t=0;
           // for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;
            for(int i=0;i<v.size();i++) t+=cal(v[i])*k;
            cout<<t<<endl;
        }
    }
    getchar(); //
    getchar();
}
