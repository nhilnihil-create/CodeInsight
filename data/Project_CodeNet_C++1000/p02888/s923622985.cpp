#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<limits>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        cin>>l[i];
    }
    sort(l.begin(), l.end());
    int count=0;
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (l[k]<(l[i]+l[j]))
                {
                    count++;
                }
                
            }
            
        }
        
    }
    cout<<count<<endl;
    
    

    return 0;
}