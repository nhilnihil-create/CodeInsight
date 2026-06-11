#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int temp=2*k+1;
    if(n%(temp)!=0)
    cout<<(n/temp)+1;
    else 
    cout<<n/temp;
}