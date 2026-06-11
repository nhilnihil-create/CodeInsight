#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
 

int main() {
	string s;
	cin>>s;
	string ch[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	for(ll i=0;i<7;i++){
		if(s==ch[i]){
			cout << 7-i;
			return 0;
		}
	}
	// your code goes here
	return 0;
}