#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,s,e) for(ll i=s;i<e;++i)

int main(){
    ll n;
    cin >> n;

    ll sum=0;
    F(a,1,n){
        sum += (n-1)/a;
    }
    cout << sum << endl;

    return 0;
}