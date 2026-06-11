#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    int k;
    cin>>k;
    int x,y;
    cin>>x>>y;
    int rem=(k-x%k)+x;
    if(x%k==0 || rem<=y)
    cout<<"OK";
    else
    cout<<"NG"<<endl;

}