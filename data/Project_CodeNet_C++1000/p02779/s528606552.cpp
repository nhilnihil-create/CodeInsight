#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+5;

set<int>s;
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int a;cin>>a;s.insert(a);
	}
	if(s.size()==n)cout<<"YES";
	else cout<<"NO";
}