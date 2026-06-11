#include<bits/stdc++.h>
using namespace std;

int k,x,low,high;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>k>>x;
    low=x-k+1;
    high=x+k-1;
    for(int i=low;i<=high;i++)
        cout<<i<<" ";
}
