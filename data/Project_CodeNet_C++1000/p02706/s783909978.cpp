#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin>>n>>m;

    int sm = 0;
    for(int i = 0; i < m; i++){
        int t;cin>>t;
        sm+=t;
    }
    cout<<((n-sm)<0?-1:(n-sm));
}
