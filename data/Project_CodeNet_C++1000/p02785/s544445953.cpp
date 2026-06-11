#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define ll long long
         
using namespace std;
     
long long gcd(int x, int y){
     if ( x == 0 ) return y;
     
     return gcd(y%x, x);
}
     
long long lcm(int x, int y){
     if ( y == 0 ){
          return x;
     }
     
     return x*y/gcd(x, y);
}
     
int min(int a, int b){
     return a > b ? b : a;
}
     
double max(double a, double b){
     return a > b ? a : b;
}

int main()
{
     cin.sync_with_stdio( false );

     ll n,k;
     cin>>n>>k;

     vector <ll> a(n);
     for (int i=0;i<n;i++){
          cin>>a[i];
     }

     sort(a.begin(), a.end());

     ll suma = 0;
     if ( k >= n ){
          cout<<0<<endl;
     }else{
          for (ll i=n-1-k;i>=0;i--){
               suma+=a[i];
          }

          cout<<suma<<endl;
     }
}