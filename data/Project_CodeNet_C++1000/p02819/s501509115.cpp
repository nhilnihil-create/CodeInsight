#include <bits/stdc++.h>
using namespace std;
int MAX=1e5+10;
vector<int> v(MAX, 1);

void soe() {
	v[0] = 0;
	v[1] = 0;
	for (int i=2; i<=sqrt(MAX); ++i) {
		if (v[i]) {
			for (int j=i*i; j<=MAX; j+=i) {
				v[j]=0;
			}
		}
	}	
}

int main() {
	int x; cin>>x;
	soe();
	while(!v[x]) {
		x++;
	}
	cout << x << endl;
	
	return 0;
}