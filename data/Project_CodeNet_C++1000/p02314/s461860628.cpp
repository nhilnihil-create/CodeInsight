#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int coin[21];
    int amount[50001];
    
    
    
    for(int i=0;i<m;i++)
    {
        cin>>coin[i];
    }
    
    for(int i=0;i<n+1;i++)
    {
        amount[i]=99999999;
    }
    amount[0]=0;
    
    for(int i=0;i<m+1;i++)
    {
        for(int j=coin[i];j<n+1;j++)
        {
            amount[j]=min(amount[j],amount[j-coin[i]]+1);
        }
    }
    cout<<amount[n]<<endl;
}