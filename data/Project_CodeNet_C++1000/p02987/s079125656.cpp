#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	map<char,ll>ch;
	for(ll i=0;i<4;i++){
		ll now=s[i]-'A';
		ch[now]++;
		if(ch[now]>2){
			cout << "No";
			return 0;
		}
	}
	for(auto itr=ch.begin();itr!=ch.end();itr++){
		ll val=itr->second;
		if(val==1){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	// your code goes here
	return 0;
}