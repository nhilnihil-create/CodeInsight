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

double expect(int x){
    double kitai,tem=0;
    for(int i=1;i<=x;i++){
        tem += i;
    }
    kitai = tem/x;
    cout << kitai << endl;
    return kitai;
    
}

int main(){
    string s, t;
    cin >> s >> t;

    int ans = INF;

    for(int i = 0; i < s.length() - t.length() + 1; i++){
        int count = 0;
        for(int j = 0; j < t.length(); j++){
            if(s[i + j] == t[j])count++;
        }   
        count = t.length() - count;
        chmin(ans, count);
    }

    cout << ans << endl;

    return 0;
}

