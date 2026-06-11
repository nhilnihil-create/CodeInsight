#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define PI 3.14159265358979323846
int main(void){
    // Your code here!
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 double a,b,h,m,x;
 cin >> a >> b >> h >> m;
 x=abs(h*30.0+(m/2.0)-m*6.0);
 x=min(360.0-x,x);
 x=(x*PI)/180.0;
 cout << std::fixed << std::setprecision(20) << sqrt((a*a)+(b*b)-(2*a*b*cos(x)));
 return 0;
}