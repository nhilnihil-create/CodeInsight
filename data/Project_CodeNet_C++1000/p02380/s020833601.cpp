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
#include<math.h>
 
using namespace std;
 
void Solution()
{
    int a, b, c;
    double h, s, l;
    
    cin>>a>>b>>c;
    
    double raid = c * 3.141592653 / 180.0 ; 
    
    h = b * sin(raid);
    s = h * a * 0.5;
    l = sqrt(a * a + b * b - 2 * a * b * cos(raid)) + a + b;
    
    cout<<fixed<<setprecision(4)<<s<<endl;
    cout<<fixed<<setprecision(4)<<l<<endl;
    cout<<fixed<<setprecision(4)<<h<<endl;

}
int main()
{
    Solution();
    return 0;
}