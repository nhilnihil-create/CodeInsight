#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d[51],x;
    long int sum;
    cin>>n;
    for(int i = 0;i<n;i++)
        cin>>d[i];
    //x = n*(n-1)/2;
    sum = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            sum += d[i]*d[j];
        }
    }
    cout<<sum;
    return 0;
}