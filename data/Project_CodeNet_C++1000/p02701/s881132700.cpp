#include <bits/stdc++.h>

using namespace std;

set <string> st;

int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		st.insert(s);
	}
	
	printf("%d\n", (int)st.size());
}
