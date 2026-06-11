#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   int n;
   cin >> n;
   vector<pair<ll,ll>>  mp(n);
   rep(i,n){
      ll a,b;
      cin >> a >> b;
      mp.at(i)=make_pair(b,a);
   }
   sort(mp.begin(),mp.end());
   ll sum=0;
   bool c=true;
   rep(i,n){
      ll bb,aa;
      tie(bb,aa)=mp.at(i);
      sum+=aa;
      if(sum>bb){
         c=false;
         break;
      }
   }
   if(c)cout << "Yes" << endl;
   else cout << "No"  << endl;
}
