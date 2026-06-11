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

int main()
{
     cin.sync_with_stdio( false );

     int n;
     cin>>n;

     int k;
     cin>>k;

     map <int, int> m;
     for (int i=0;i<k;i++){
          int d;
          cin>>d;

          for (int j=0;j<d;j++){

               int a;
               cin>>a;

               m[a]++;
          }
     }

     int br = 0;
     for (int i=1;i<=n;i++){
          if ( m[i] == 0 ){
               br++;
          }

     }

     cout<<br<<endl;
}