#include <bits/stdc++.h>
using namespace std;
/*  Writen by : AS7
 *  "JUST KEEP GOING..."
 */
#define endl			'\n'
#define ll				long long
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define For(i,s)        for(auto i:s)
#define Forr(i,s)        for(auto &i:s)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define vi				vector <int>
#define vl				vector <ll>
#define ii				pair <int,int>
#define vii				vector <ii>
#define vll				vector <pair<ll,ll>>
#define PI				double PPPPPP = 3.14159265358979323846;
#define bit(mask,i) ((mask>>i)&1)
const int N = 2e5+5;
map<int,int> pos;
ll sum=0;
void solve(){
   int n,m,k,ans=0;
   cin>>n>>m>>k;
   set<int> ss;
   vi A(n),B(m);
   Forr(i,A)cin>>i;
   int ind=0;
   Forr(i,B){
       ss.insert(sum);
       pos[sum]=ind;
       cin>>i;
       sum+=i;
       ind++;
   }
   ss.insert(sum);
   pos[sum]=m;
   sum=0;
    for (int i = 0; i <n ; ++i) {
          int rem=k-sum;
          if(rem<0)
              break;
          auto it=ss.lower_bound(rem);
          if(*it>rem)--it;
          ans=max(i+pos[*(it)],ans);
          sum+=A[i];
    }
    int rem=k-sum;
    if(rem>=0) {
        auto it = ss.lower_bound(rem);
        if(*it>rem)--it;
        ans = max(n + pos[*(it)], ans);
    }
    cout<<ans<<endl;
}
int main() {
    int t = 1;
  //  cin>>t;
    while (t--)solve();
}