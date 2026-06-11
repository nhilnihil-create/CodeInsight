#include <bits/stdc++.h>
#include<algorithm>	
using namespace std;
#define ll long long 
long long n;
vector<long long> so_a;//素数を格納
int main(){
  long double a,b,x;
  cin >> a >> b >> x;
  long double res;
  if(x > a*a*b/2){
    
    res = atan(2*(a*a*b-x)/(a*a*a));
  }else{
    res = atan((a*b*b)/(2*x)) ;
  }
  cout << fixed << setprecision(10);
  cout << 360*res/(2*M_PI) << endl;

}
