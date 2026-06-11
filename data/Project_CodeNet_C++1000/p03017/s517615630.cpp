#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	string s; cin >> s;
	s.push_back('#'); s.push_back('#');
	n += 2;
	a--, b--, c--, d--;

	if(c > d) {
		swap(c, d);
		swap(a, b);
	}
	int cnt = 0;

//	cout << a << " " << b << " " << c << " " << d << endl;
	s[a] = 'A', s[b] = 'B';

	while(a != c || b != d) {

		if(s[b + 1] == '.' && b + 1 <= d) {
			s[b] = '.';
			b += 1;
			s[b] = 'B';
		} else if(s[b + 2]== '.' && b + 2 <= d) {
			s[b] = '.';
			b += 2;
			s[b] = 'B';
		} else if(s[a + 1] == '.' && a + 1 <= c) {
			s[a] = '.';
			a  += 1;
			s[a] = 'A';
		}else if(s[a + 2] == '.' && a + 2 <= c) {
			s[a] = '.';
			a += 2;
			s[a] = 'A';
		}
		//cout << "cnt : " << cnt << " a : " << a << " b : " << b << " " << s << endl;
		cnt++;
		if(cnt >= 10 * n) {
			cout << "No" << endl;
			return 0;
		}
	} 
	cout << "Yes" << endl;
}	