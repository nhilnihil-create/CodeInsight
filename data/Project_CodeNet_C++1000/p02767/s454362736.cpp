#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n;
   cin>>n;
   vector<int> x(n);
   rep(i, n) cin>>x[i];

   int mn=INT_MAX;
   rep(p, 101){
      int sm=0;
      rep(i, n) sm+= (x[i]-p)*(x[i]-p);
      mn=min(mn, sm);
   }

   cout<<mn<<endl;
   return 0;
}
