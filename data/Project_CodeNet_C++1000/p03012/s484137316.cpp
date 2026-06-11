#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,i,sum=0,sum1=0,min1;
    cin>>t;
    int a[t];
    for(i=0;i<t;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    min1=INT_MAX;
    for(i=0;i<t;i++)
    {
        sum-=a[i];
        sum1+=a[i];
        min1=min(abs(sum-sum1),min1);
    }
    cout<<min1<<endl;
}