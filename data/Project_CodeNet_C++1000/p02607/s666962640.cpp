#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int i,cnt=0;
    for(i=0;i<n;i++)    cin>>arr[i];
    for(i=0;i<n;i+=2)
        if(arr[i]&1)  cnt++;

    cout<<cnt<<endl;
}
