#include<bits/stdc++.h>
using namespace std;

#define ll long long int

static const auto _____ = []() {
    // fast IO code : this I understand
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(0);
    return 0;
}();

int main(){
	int n;
	cin>>n;
  	ll sum = 0;
  	for(int i=1;i<n;i++){
		sum += (n-1)/i;
	}
  	cout<<sum<<endl;
	return 0;
}