#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a[i]=x-y;
    }
    x=2;
    for(int i=0;i<n-2;i++){
        if(a[i]==0){
            if(a[i+1]==0 && a[i+2]==0){
                x=0;
            }
        }
    }
    if(x==0){
        cout<<"Yes";
    }else
    cout<<"No";
}
