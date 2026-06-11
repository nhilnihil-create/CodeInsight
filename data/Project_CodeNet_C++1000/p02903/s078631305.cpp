#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;

void out(int i){
    if(i==1)cout<<1;
    if(i==-1)cout<<0;
}

int main(){
   ll H, W, A, B;
   cin>>H>>W>>A>>B;
   A;
   B;
   rep(i, H){
       rep(j, W){
           int K=1;
           if(i>=B)K*=-1;
           if(j>=A)K*=-1;
           out(K);
       }
       cout<<endl;
   }
}

