#include <bits/stdc++.h>
//#include <cmath>
//using namespace std; 
//bool is_integer( double x ){
//  return std::floor(x)==x;
//}
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}
int main(){
	int k, ans, x;
  	cin >> x;
  	if(1<=x&&x<=179){
      	ans = (lcm(360, x))/x;
      	cout << ans << endl;
    }
}

