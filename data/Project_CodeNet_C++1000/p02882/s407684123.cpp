#include <bits/stdc++.h>
#define INF 1e7
#define dsec 86400

using namespace std;
typedef long long int ll;
typedef tuple<int,int,int> tii;
typedef tuple<long long int,long long int,long long int> tll;
typedef tuple<double,double,double> tdd;



int main()
{
   double a,b,x; cin >> a >> b >> x;
   if(2*x <= a*a*b)
   {
       double y = atan(a*b*b/(2*x));
       cout << fixed << setprecision(10) << y*180 / 3.1415926535 << endl;
   }
   else
   {
       double y = atan(2*(b/a - (x / (a*a*a))));
       cout << fixed << setprecision(10) << y*180 / 3.1415926535 << endl;
   }
}