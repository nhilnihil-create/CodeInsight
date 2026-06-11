#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n;
   cin>>n;
   vector<int> x(n), y(n);
   rep(i, n) cin>>x[i]>>y[i];

   int a=1;
   rep(i, n) a*=(i+1);
   int pat=a;
   int tm=pat*(n-1);
   int am=n*(n-1)/2;
   int m=tm/am;
   double ad=0;
   rep(i, n) for(int j=i+1; j<n; j++){
      ad+= sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
   }
   double avem=ad/am;
   double avee=avem*(n-1);

   cout << std::fixed << std::setprecision(15) << avee << endl;
   return 0;
}
