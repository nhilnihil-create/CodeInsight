#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    int a[n], b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    bool Wmax=false;
    if(b[n-1]==b[n-2]){
        Wmax=true;
    }
    
    if(Wmax==true){
        for(int i=0; i<n; i++){
            cout<<b[n-1]<<endl;
        }
    }else{
        for(int i=0; i<n; i++){
            if(a[i]==b[n-1]){
                cout<<b[n-2]<<endl;
            }else{
                cout<<b[n-1]<<endl;
            }
        }
    }
    return 0;
}