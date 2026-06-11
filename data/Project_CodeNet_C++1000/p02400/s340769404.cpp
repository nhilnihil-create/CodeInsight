#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstdlib>
#include<iomanip>
#include<queue>
#include<set>
#include <valarray>
#include<stack>
#include<sstream>

using namespace std;

void Solution()
{
    double r;
    
    cin>>r;
   
    cout<<fixed<<setprecision(6)<<M_PI * r * r<<" "<<M_PI * r * 2<<endl;
      //M_PI = pi , need include math.h
}

int main()
{
    Solution();
    return 0;
}