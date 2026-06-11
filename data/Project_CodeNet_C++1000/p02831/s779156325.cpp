#include<bits/stdc++.h>
#include<numeric>
#include <boost/math/common_factor.hpp> 
#define int long long
using namespace std;
int32_t main()
{
 int a,b;
       cin>>a>>b;
       cout<<boost::math::lcm(a,b);
}