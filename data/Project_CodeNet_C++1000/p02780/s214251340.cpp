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

     int n,k;
     cin>>n>>k;

     double a[n];
     for (int i=0;i<n;i++){
          cin>>a[i];
          a[i] = (a[i] + 1) / 2;
          //cout<<a[i]<<" ALO"<<endl;
     }

     vector <double> dp(n+5, 0);
     for (int i=1;i<=n;i++){
          dp[i]=dp[i-1] + a[i-1];
          //cout<<dp[i]<<" "; 
     }

     //cout<<endl;

     double res = 0;
     for (int i=0;i<=n-k;i++){
          //cout<<dp[i+k]<<" ALO "<<dp[i]<<endl;
          double buff=dp[i+k]-dp[i];
          //cout<<buff<<" ALO1"<<endl;
          res=max(res, buff);
          //cout<<i<<" "<<k<<" "<<res<<endl;
     }

     cout<<fixed<<setprecision(15)<<(double)(res)<<endl;
}