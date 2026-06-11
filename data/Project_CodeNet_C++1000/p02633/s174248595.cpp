#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;
const double eps=1e-10;
int main()
{
  int x;
  cin>>x;
  pair<double,double> pos={0,0};
  int ans=0;
  do
  {
    double theta=(90+ans*x)*M_PI/180;
    pos.first+=cos(theta);
    pos.second+=sin(theta);
    ans++;
  }while(abs(pos.first)>eps||abs(pos.second)>eps);
  cout<<ans<<endl;
}