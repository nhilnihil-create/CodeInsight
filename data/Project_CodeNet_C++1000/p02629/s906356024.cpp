#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define lop(i,a,b) for(ll i=a;i<b;i++)
using namespace std;

void func(){
    ll n;
    cin>>n;
    vector<char> a;
    while(n>0){
        n--;
        a.push_back((char)(97+(n%26)));
        n/=26;
    }
    for(int i=a.size()-1;i>=0;i--)cout<<a[i];
    cout<<endl;
}

int main(){
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        func();
    }
}