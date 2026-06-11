#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int n;
string s;
map<string, int> mp;
int tot;
int main() {
	cin>>n;
	for (int i=1;i<=n;++i) {
		cin>>s;
		if (!mp.count(s)) {
			mp[s]=1;
			++tot;
		}
	}
	printf("%d\n",tot);
	return 0;
}