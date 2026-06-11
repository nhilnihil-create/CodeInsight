#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_code(drken)
int main() {
    ll n;cin>>n;
    string a = "";
    while(n>0){
        --n;
        a += 'a' + (n%26);
        n/=26;
    }
    reverse(a.begin(),a.end());
    cout<<a<<endl;
	return 0;
}