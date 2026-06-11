#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007


int main() {
	string s;
	cin>>s;
	bool ch=true;
	if(s.size()%2!=0){
		cout << "No";
		return 0;
	}
	for(ll i=0;i<s.size();i+=2){
		string k;
		k+=s[i];
		k+=s[i+1];
		//cout << k<<endl;
		if("hi"!=k){
			ch=false;
		}
	}
	cout << (ch?"Yes":"No");
	return 0;
}