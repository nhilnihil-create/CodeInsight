#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double sum=0;
    cin>>n;
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    cin>>arr[i];
    for(i=0;i<n;i++){
        sum+=1*1.0/arr[i];
    }
    cout<<1*1.0/sum<<endl;
}