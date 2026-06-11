#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define rep11(i, n) for (int i = 1; i < (int)(n); ++i)
#define repo(i, o, n) for (int i = o; i < (int)(n); ++i)
#define repm(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1002000007
#define INF LONG_LONG_MAX

typedef pair<int, int> P;
int main(){
   long long n;
   cin>>n;
   vector<long long>p(n);
   rep(i,n){
       cin>>p[i];
   }
   int ans=0;
   for(int i=2;i<n;i++){
       vector<long long> tp(3);
       tp[0]=p[i-2];
       tp[1]=p[i-1];
       tp[2]=p[i];
       sort(tp.begin(),tp.end());
       if(tp[1]==p[i-1]){
           ans++;
       }
   }
   cout<<ans<<endl;
}
