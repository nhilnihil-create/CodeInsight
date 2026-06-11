#include<iostream>
#include<set>
using namespace std;

int main()
{
	int N;
	char s[11];
	set<string> S;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		S.insert(s);
	}
	cout << S.size() << endl;
	return 0;
}