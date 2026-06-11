#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;

int main(){
    int n;cin>>n;
    string s[n];for(int i=0;i<n;i++){cin>>s[i];sort(s[i].begin(),s[i].end());}
    ll sum=0;
    map<string,ll> box;
    for(int i=0;i<n;i++){
        box[s[i]]+=1;
    }
    for(auto p:box){
        ll i = p.second;
        sum+=i*(i-1)/2;
    }
    cout <<sum;
    
}