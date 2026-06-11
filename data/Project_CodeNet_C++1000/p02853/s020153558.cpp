#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,s=0,s1=0,count=0;
    cin>>x>>y;
ios::sync_with_stdio(0);
    if(x==3){s=100000;}
    else if(x==2){s=200000;}
    else if(x==1){s=300000;}

     if(y==3){s1=100000;}
    else if(y==2){s1=200000;}
    else if(y==1){s1=300000;}



    count=s+s1;
    if(count==600000){cout<<"1000000"<<endl;}
    else
    cout<<count<<endl;
    return 0;
}