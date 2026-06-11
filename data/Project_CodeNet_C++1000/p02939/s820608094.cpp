#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> s;
	n = s.length();
	int cnt = 0;
	string pre = "";
	for(int i = 0; i < n; ++ i) {
		++ cnt;
		string now = "";
		now += s[i];
		if(pre == now)
			++ i, now += s[i];
		if(i == n) {
			-- cnt;
			break;
		}
		pre = now;
	}
	cout << cnt << endl;

    return 0;
}
