#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	vector<int> v(n);
	for(int i=1; i<n; i++){
		int a; cin>>a;
		v[a-1]++;
	}
	for(auto x:v) cout<<x<<endl;
}