#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,p=0; cin>>n;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(i*j==n){p=1;}
        }
    }
    if(p==1)cout<<"Yes";
    else cout<<"No";
}

