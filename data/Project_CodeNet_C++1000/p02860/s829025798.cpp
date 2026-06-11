#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,flag=0;
    cin>>n;
    char arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];
    if(n<=1)
    cout<<"No"<<endl;
    else if(n%2!=0)
    cout<<"No"<<endl;
    else
    {
        for(i=0;i<n/2;i++)
        {
            if(arr[i]!=arr[n/2+i])
            {
                flag++;
                break;
            }
        }
        if(flag==0)
        cout<<"Yes"<<endl;
        else
        {
            cout<<"No"<<endl;
        }
        
    }
    
}