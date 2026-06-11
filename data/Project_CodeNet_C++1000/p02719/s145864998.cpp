#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
    ll n,k; cin>>n>>k;
    cout<<min(n%k,k-n%k);
    return 0;
}
