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

ll h;

ll solve(ll a){
     if ( a == 1 ){
          return 1;
     }

     return 1 + 2*solve(a/2);
}

int main()
{
     cin.sync_with_stdio( false );
     cin>>h;
     cout<<solve(h)<<endl;
}