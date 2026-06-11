#include<iostream>
using namespace std;
int main(){
    int n,a[100000],b[100000],i;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
        b[a[i]-1]=i+1;
    }
    for(i=0;i<n-1;i++){
        cout<<b[i]<<" ";
    }
    cout<<b[n-1]<<endl;
}
