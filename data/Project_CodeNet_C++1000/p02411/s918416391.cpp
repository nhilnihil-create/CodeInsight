#include <iostream>
using namespace std;

int main()
{
		int m[10000], f[10000], r[10000], i, n;
		while (1) {
				cin >> m[n] >> f[n] >> r[n];
				if (m[n]==-1 && f[n]==-1 && r[n]==-1) break;
				n++;
		}

		for (i=0; i<n; i++) {
				if (m[i]==-1 || f[i]==-1) cout << "F\n";
				else if (m[i]+f[i]>=80) cout << "A\n";
				else if (m[i]+f[i]>=65 && m[i]+f[i]<80) cout << "B\n";
				else if (m[i]+f[i]>=50 && m[i]+f[i]<65) cout << "C\n";
				else if (m[i]+f[i]>=30 && m[i]+f[i]<50) {
						if (r[i]>=50) cout << "C\n";
						else cout << "D\n";
				} else cout << "F\n";
		}
}