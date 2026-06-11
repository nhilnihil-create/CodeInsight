#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    n--;
    for(int i=k-n;i<=k+n;i++)
        cout<<i<<" ";
    cout<<endl;
}
