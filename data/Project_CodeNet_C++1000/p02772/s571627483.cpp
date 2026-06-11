#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,flag=0;
    cin>>n;
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    cin>>arr[i];
    for(i=0;i<n;i++){
        if(arr[i]%2==0){
            if(!(arr[i]%3==0 || arr[i]%5==0))
            {flag++;
            break;
            }
        }
    }
    if(flag==1)
    cout<<"DENIED"<<endl;
    else
    {
        cout<<"APPROVED"<<endl;
    }
    
}