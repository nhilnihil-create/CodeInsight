#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	map<char,ll>a;
	for(ll i=0;i<s.size();i++){
		a[s[i]]++;
	}
	bool ch=true;
	for(auto itr=a.begin();itr!=a.end();itr++){
		ll val=itr->second;
		if(val!=2){
			ch=false;
		}
    }
    cout << (ch?"Yes":"No");
	// your code goes here
	return 0;
}