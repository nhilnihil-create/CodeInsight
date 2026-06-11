#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const char nl = '\n';

// INT VS LL

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    ll a,b,k;
    cin>>a>>b>>k;
    if (k<=a){
    	cout<<a-k<<" "<<b<<nl;
    }
    else{
    	k-=a;
    	if (k<=b){
    		cout<<0<<" "<<b-k<<nl;
    	}
    	else cout<<0<<" "<<0<<nl;
    }
    return 0;
}