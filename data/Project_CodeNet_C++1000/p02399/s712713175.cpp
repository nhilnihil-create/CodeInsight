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
    int a, b;
    
    int d, r;
    double f;
    
    cin>>a>>b;
    
    d = a / b;
    r = a % b;
    f = (double)a / b;
    
    cout<<d<<" "<<r<<" "<<fixed<<setprecision(5)<<f<<endl;
    
}

int main()
{
    Solution();
    return 0;
}