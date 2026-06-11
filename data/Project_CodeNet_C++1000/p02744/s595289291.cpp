#include <bits/stdc++.h>

using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define dump(x) cerr << "~ " << #x << " = " << x << endl

std::vector<int> v;
int n;

void rec(int pos, int val) {

	if(pos == n+1) {

		for(int i = 0; i < n; i++) {
			char ch = 'a'+v[i]-1;
			cout << ch;
		}

		cout << endl;
		return;
	}

	for(int i = 1; i <= val+1; i++) {
		
		v.push_back(i);
		rec(pos+1, max(val,i));

		v.pop_back();
	}
}

int main() {

	fast_cin;

	
	cin >> n;

	rec(1,0);
	
	
	
	return 0;
}