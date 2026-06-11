#include<iostream>
using namespace std;
int main(){
    int a[100],i,n,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[n-1];
    for(j=n-2;j>=0;j--){
        cout<<" "<<a[j];
    }
    cout<<endl;
    
    return 0;
}