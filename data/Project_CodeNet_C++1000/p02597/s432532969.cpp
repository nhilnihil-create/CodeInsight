#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0;
    cin>>n;
    char c[n];
    for(int k=0;k<n;k++){
        cin>>c[k];
    }
    int i=0,j=n-1;
    while(i<j){
        while(c[i]=='R'){
            i++;
        }
        while(c[j]=='W'){
            j--;
        }
        if(i<j){
            ans++;
            i++;
            j--;
        }
    }
    cout<<ans;
    return 0;
}