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
    int H, W;
    
    while(cin>>H>>W)
    {
        if (H == 0 || W == 0)
        {
            break;
        }
        
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cout<<"#";
            }
            
            cout<<endl;
        }
        
        cout<<endl;
    }
    
    
}

int main()
{
    Solution();
    return 0;
}