#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define lop(i,a,b) for(ll i=a;i<b;i++)
using namespace std;

void func(){
    char a;
    cin>>a;
    if(a<97)cout<<"A"<<endl;
    else cout<<"a"<<endl;
}

int main(){
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        func();
    }
}