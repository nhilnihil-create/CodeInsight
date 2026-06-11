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

#define inf 1e9

int main()
{
     cin.sync_with_stdio( false );

     int h;
     cin>>h;

     vector <int> dp(h+5, inf); dp[0] = 0;

     int n;
     cin>>n;

     pair <int, int> att[n];
     for (int i=0;i<n;i++){
          int a,b;
          cin>>a>>b;
          att[i] = {a, b};
     }

     for (int i=0;i<n;i++){
          for (int j=0;j<=h;j++){
               if ( dp[j] != inf ){
                    //pozicija j ali - a - skidas -> j + a
                    dp[min(j+att[i].first, h)] = min(dp[min(j+att[i].first, h)], dp[j] + att[i].second);
               }
          }
     }

     cout<<dp[h]<<endl;
}