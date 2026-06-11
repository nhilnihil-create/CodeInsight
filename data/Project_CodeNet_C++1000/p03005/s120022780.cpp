#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,k;
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>k>>n;
    if(n>1){
        cout<<abs(n-k)<<endl;
    }
    else cout<<"0"<<endl;
	return 0;
}
