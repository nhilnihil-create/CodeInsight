#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,product=0;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    cin>>arr[i];
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++)
        {
            product+=arr[i]*arr[j];
        }
    }
    cout<<product<<endl;
}