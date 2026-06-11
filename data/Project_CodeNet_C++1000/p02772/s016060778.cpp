#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    cin>>arr[i];
    int temp=1;
    for(i=0;i<n;i++){
        if(arr[i]%2==0 && !(arr[i]%3==0 || arr[i]%5==0)){
            temp=0;
            break;
        }
    }
    if(temp)
    cout<<"APPROVED";
    else
    cout<<"DENIED";
    return 0;
}