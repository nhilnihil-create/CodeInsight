#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    
    if(n%2==1){
        n/=2;
        cout<<b[n]-a[n]+1<<endl;
    }else{
        n/=2;
        cout<<b[n]-a[n]+b[n-1]-a[n-1]+1<<endl;
    }
}