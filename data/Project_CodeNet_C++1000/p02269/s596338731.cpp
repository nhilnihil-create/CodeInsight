#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;
#define rep(x,to) for(int x=0; x<(to); (x)++)


int main() {
	int n;
	char s[5];
	string t;
	set<string> Set;
	cin >> n;
	rep(i,n) {
		scanf("%s", s);
		if(s[0] == 'i') {
			cin >> t;
			Set.insert(t);
		} else {
			cin >> t;
			if(Set.find(t) == Set.end()) printf("no\n");
			else printf("yes\n");
		}
	}
	return 0;
}