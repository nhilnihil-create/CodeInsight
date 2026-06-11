#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, t;
    cin>>n>>x>>t;
    int k=n;
    int count=k/x;
    if(n%x>0)
    count++;
    count=(count*t);
    cout<<count<<endl;
}