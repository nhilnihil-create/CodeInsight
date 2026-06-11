#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll a,v,b,w,t;
    cin>>a>>v>>b>>w>>t;
    if (abs(b-a)<=((v-w)*t)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}