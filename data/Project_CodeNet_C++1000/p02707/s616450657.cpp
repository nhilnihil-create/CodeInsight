#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long num;
    while(cin>>num)
    {
        long long arr[num+5],count[num+5]={0};
        for(long long i=0;i<num-1;i++)
        {
            cin>>arr[i];
            count[arr[i]]++;
        }
        for(long long i=1;i<=num;i++)
        {
            cout<<count[i]<<endl;
        }
      break;
    }
}
