#include <iostream>
#include <string>
using namespace std;

int main()
{
		int m, i, j, k;
		string s, sub, temp;
		while (1) {
				cin >> s;
				if (s=="-") break;
				cin >> m;
				int h[m];
				for (i=0; i<m; i++) cin >> h[i];

				for (i=0; i<m; i++) {
						s = s.substr(h[i],s.size()-h[i]) + s.substr(0,h[i]);
				}
				cout << s << "\n";
		}
}