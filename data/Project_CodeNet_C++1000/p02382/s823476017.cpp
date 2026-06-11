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
    int n;
    int x[100] = {0};
    int y[100] = {0};
    
    double sum1 = 0;
    double sum2 = 0;
    double sum3 = 0;
    double sumMax = 0;
    
    
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        cin>>x[i];
    }
    
     for(int i = 0; i < n; i++)
    {
        cin>>y[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        sum1 = (double)fabs(x[i] - y[i]) + sum1;
        sum2 = (double)(x[i] - y[i]) * (x[i] - y[i]) + sum2;
        sum3 = (double)fabs((x[i] - y[i]) * (x[i] - y[i]) * (x[i] - y[i]))+ sum3;
        sumMax = max(sumMax, (double)fabs(x[i] - y[i]));  //"Max" in this question just means that who is bigger
    }
    
    cout<<fixed<<setprecision(5)<<sum1<<endl;
    cout<<fixed<<setprecision(5)<<sqrt(sum2)<<endl;
    cout<<fixed<<setprecision(5)<<pow(sum3, 1.0/3.0)<<endl;    //or cbrt(num)
    cout<<fixed<<setprecision(5)<<sumMax<<endl;
    
    
    
    
}
 
int main()
{
    Solution();
    return 0;
}