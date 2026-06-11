#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define lop(i,a,b) for(ll i=a;i<b;i++)
using namespace std;

void func(){
    float d,t,s;
    cin>>d>>t>>s;
    if((d/s)<=t)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        func();
    }
}