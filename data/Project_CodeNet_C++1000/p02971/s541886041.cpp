#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a[200005],b[200005],one,two;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    one=b[n-1];
    two=b[n-2];
    for(int i=0;i<n;i++){
        if(a[i]!=one){
            cout<<one<<endl;
        }
        else{
            cout<<two<<endl;
        }
    }
    return(0);
}