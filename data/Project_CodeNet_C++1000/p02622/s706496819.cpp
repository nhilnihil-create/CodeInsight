#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
  	cin.tie(0);
  	string n,m;
  	cin >> n >> m;
  	int count = 0;
  	for(int i = 0;i<int(m.size());++i) {
		if(n[i] != m[i])
          count++;
    }
  	cout << count;
}