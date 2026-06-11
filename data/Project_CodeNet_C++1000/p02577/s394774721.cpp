#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
char s[N];
int sum;
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> s;
    for(int i = 0; s[i]; i++) sum += s[i] - '0';
    if(sum % 9) cout << "No" << endl;
    else cout << "Yes" << endl;
	return 0;
}
