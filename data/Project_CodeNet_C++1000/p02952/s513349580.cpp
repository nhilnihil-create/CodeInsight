#include <bits/stdc++.h>
using namespace std;



int main() {
	int N,ans=0;
	string tmp;
	cin>> N;
	for (int i = 1; i <=  N; i++)
	{
		tmp = to_string(i);
		if (tmp.size() % 2 == 1)ans++;
	}
	cout << ans << endl;
}