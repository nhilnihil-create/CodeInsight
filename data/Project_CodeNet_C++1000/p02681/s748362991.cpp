#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s,t;

int main(void){
	cin >> s;
	cin >> t;
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]!=t[i]){
			flag=false;
		}
	}
	printf("%s\n",flag?"Yes":"No");
	return 0;
}
