#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ulong N;
    cin>>N;

    vector<vector<ulong>> AB(10,vector<ulong>(10));

    for (ulong i = 1; i < N+1; i++)
    {
        ulong a=i;
        ulong b=i%10;
        while(a>9)
        {
            a/=10;
        } 
        AB[a][b]++;
    }
    

    ulong ans = 0;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            ans+=AB[i][j]*AB[j][i];
        }    
    }
    
    cout<<ans<<endl;
    return 0;
}