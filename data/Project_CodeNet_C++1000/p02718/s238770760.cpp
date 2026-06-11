#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    long long int arr[n];
    int i;
    long long int sum=0,count=0;
    for(i=0;i<n;i++)
    {cin>>arr[i];
        sum+=arr[i];
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]*4*m>=sum)
        count++;
    }
    if(count>=m)
    cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
    

}