#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
   int n;
   cin>>n;
   double bo=0;
   rep(i,n){
       double a;
       cin>>a;
       bo+=1/a;
   }
   cout<<fixed<<setprecision(10)<<1/bo<<endl;
}