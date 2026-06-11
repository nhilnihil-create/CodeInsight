#include <bits/stdc++.h>

using namespace std;

int main() {
	unordered_set <int> st;
	st.insert(1); st.insert(2); st.insert(3);

	int a, b; cin >> a >> b; st.erase(a); st.erase(b);

	cout << *begin(st); 
}