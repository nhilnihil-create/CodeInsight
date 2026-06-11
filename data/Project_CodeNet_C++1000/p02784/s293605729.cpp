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

     int h,n;
     cin>>h>>n;

     int a = 0;
     for (int i=0;i<n;i++){
          int b;
          cin>>b;
          a+=b;
     }

     if ( a >= h ){
          cout<<"Yes"<<endl;
     }else{
          cout<<"No"<<endl;
     }
}