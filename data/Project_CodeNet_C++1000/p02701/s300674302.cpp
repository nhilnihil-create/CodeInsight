#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	set<string> st;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		st.insert(S);
	}
	printf("%d", st.size());

	return 0;
}
