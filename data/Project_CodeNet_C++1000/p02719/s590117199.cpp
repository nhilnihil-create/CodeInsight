#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    ll n, k;
    cin>>n>>k;
    n %=k;
    if(n>llabs(n-k)){
        n=llabs(n-k);
    }
    cout<<n<<endl;
}