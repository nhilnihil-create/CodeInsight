#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 1e5;

int main() {
//#ifndef ONLINE_JUGDE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin>>n;
    string ans="";
    while(n){
    	ll ch=n/26;
    	ll z=n%26;
    	if(z==0){
    		ch--;
    		ans=(char)('z')+ans;
		}
		else
			ans=(char)('a'+z-1)+ans;
		n=ch;
	}
	cout<<ans;
    return 0;
}