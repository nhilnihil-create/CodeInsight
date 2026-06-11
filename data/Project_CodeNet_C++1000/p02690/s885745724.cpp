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
     
int max(int a, int b){
     return a > b ? a : b;
}

ll stepen(ll n, ll a){
     ll p = n;
     for (int i=0;i<a-1;i++){
          p*=n;
     }

     return p;
}

int main()
{
     cin.sync_with_stdio( false );
     ll x;
     cin>>x;

     for (int i=-120;i<=120;i++){
          for (int j=-120;j<=120;j++){
               //cout<<i<<" "<<j<<" "<<stepen(i, 5)<<" "<<stepen(j, 5)<<endl;
               if ( stepen(i, 5) - stepen(j, 5) == x || stepen(j, 5) - stepen(i, 5) == x ){
                    cout<<max(i, j)<<" "<<min(i, j)<<endl;
                    return 0;
               }
          }
     }
}