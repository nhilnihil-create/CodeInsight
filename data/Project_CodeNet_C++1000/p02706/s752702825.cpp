#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long N,M,sum=0,p;
    cin>>N>>M;
    int arr[M];
    for(int i=0;i<M;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(N>=sum)
    {
        cout<<N-sum;
    }
    else
    {
        cout<<"-1";
    }
}
