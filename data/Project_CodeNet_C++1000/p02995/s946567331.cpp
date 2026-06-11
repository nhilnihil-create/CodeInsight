#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
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

long long lcm(long long a, long long b)
{
   return a * b / gcd(a, b);
}


long long nsolver(long long n,long long x, long long y){
        return n - (n/x + n/y - n/(lcm(x,y)));
}


int main(){
	long long a,b,c,d;
    cin >> a >> b >> c >> d;

    cout << nsolver(b,c,d) - nsolver(a-1,c,d) << endl;


}