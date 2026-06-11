#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define BR cout<<endl;
#define LEN(s) s.length();
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const ll mod=1000000007;

ll powmod(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
        res=res*x%mod;
    }
    return res;
}

int main(){
    int n, x = 0, num = 0;
    cin >> n;
    int ans[n];
    rep(i,n)ans[i] = 0;

    string s[n], tem[n];
    rep(i,n){
        cin >> s[i];
        tem[i] = "";
    }
    sort(s, s+n);

    rep(i,n){
        if(i == 0){
            tem[0] = s[0]; 
            ans[x] += 1;
        }
        else{
        if(tem[x] == s[i]){
            ans[x] += 1;
        }
        else{
            x++;
            tem[x] = s[i];
            ans[x] += 1;
        }
        }
        chmax(num, ans[x]);
    }

   
    rep(i,n){
        if(ans[i] == num){
            cout << tem[i] << endl;
        }
    }

    return 0;
}

