#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n
  ll a,b,h,m;
  cin>>a>>b>>h>>m;
  double hdeg = h*30;
  double mdeg = m*6;
  hdeg += mdeg/12;
  double angle = abs(hdeg-mdeg);
  double cosangle = cos(angle * PI/180);
  cout << fixed  << setprecision(20) << sqrt(a*a+b*b -2*a*b*cosangle) << endl;

    return 0;

}
