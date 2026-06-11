#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int gcd(int a,int b){
    if(a%b==0) return(b);
    else return(gcd(b,a%b)); 
}

int main(){
    ll k,ans=0;cin >> k;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                ll tem = gcd(i,j);
                ans += gcd(tem,l);
            }
        }
    }
    
    cout << ans << endl;
}