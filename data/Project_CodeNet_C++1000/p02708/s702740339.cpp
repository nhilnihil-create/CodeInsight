#include<bits/stdc++.h>
using namespace std;
const int N = 1e9+7;
using ll = long long;

int main(){
    int n,k;
    cin>>n>>k;

    ll sm = 0;
    for(int i = k; i <= n+1; i++){
       ll mn = 1LL*i*(i-1)/2;
       ll ts =1LL* n*(n+1)/2;
       ll mx = 1LL*(n-i)*(n-i+1)/2;
       sm += (ts-mx) - mn + 1;
       sm%=N;
    }
    cout<<sm%N;
}
