#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;


int main(){
    AC
    ll x;
    cin>>x;
    ll ans = 100;
    ll years = 0;
    while(ans<x){
        ans+=(ans/100);
        years++;
    }
    cout<<years<<endl;
}