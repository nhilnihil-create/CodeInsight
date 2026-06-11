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
    while(1)
    {
         int n;
        long int s[1000] = {0};
        double m;
        long int sum = 0;
        double aa = 0;
        
        cin>>n;
    
        if(n == 0) break;
        
        for(int i = 0; i < n; i++)
        {
            cin>>s[i];
        }
    
        for(int i = 0; i < n; i++)
        {
            sum += s[i]; 
        }
    
        m = (double)sum / n;  //type change !
    
        for(int i = 0; i < n; i++)
        {
            aa += (s[i] - m) * (s[i] - m);
        }
        
        cout<<fixed<<setprecision(4)<<sqrt(aa / n)<<endl;
    }
        
}

int main()
{
    Solution();
    return 0;
}