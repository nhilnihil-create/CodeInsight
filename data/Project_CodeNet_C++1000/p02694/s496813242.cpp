#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN=1e5+1;
vector<string>op(mxN);

vector<char>ans;

signed main(){
    int x;
    cin>>x;
    int b=100;
    int ans=0;
    while(b<x){
        b+=b/100;
        ans+=1;
    }
    cout<<ans<<endl;
}