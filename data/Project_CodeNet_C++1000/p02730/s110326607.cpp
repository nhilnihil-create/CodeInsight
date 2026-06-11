#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
	string t,u;
int main() {
	string s;

	cin>>s;	ll n=s.size();
	string S=s,k;
	bool ch=true;
	reverse(S.begin(),S.end());
	if(s!=S){
		ch=false;
	}
//	cout << ch<<endl;

	for(ll i=0;i<(n-1)/2;i++){
//		cout << i<<endl;
		t.push_back(s[i]);
		k=t;

	}
		reverse(k.begin(),k.end());
		if(t!=k){
			ch=false;
		}	
	for(ll i=(n+3)/2-1;i<n;i++){
//		cout << i<<endl;
		u.push_back(s[i]);
		k=u;
	}
		reverse(k.begin(),k.end());
		if(u!=k){
			ch=false;
		}	
	if(ch){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	// your code goes here
	return 0;
}