#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool issorted(vector<int> &v)
{
	for(int i = 1; i < v.size(); i++)
		if(v[i] < v[i - 1])
			return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	if(issorted(v)){
		cout << "YES";
		return 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			swap(v[i], v[j]);
			if(issorted(v))
			{
				cout << "YES";
				return 0;
			}
			swap(v[i], v[j]);
		}
	}
	cout << "NO";
	return 0;
}
