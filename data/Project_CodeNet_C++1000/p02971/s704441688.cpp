#include<iostream>
#include<vector>
#include<algorithm>
#define pb push_back
#define rep(i, n) for(i=0; i<n; i++)
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> se, ne;
	int i;
	rep(i, n){
		int x;
		cin >> x;
		se.pb(x);
		ne.pb(x);
	}
	//int j;
	sort(ne.begin(), ne.end(), greater<int>());
	rep(i, n){
		if(se[i]!=ne[0]){
			cout << ne[0] << endl;
		}
		else{
			cout << ne[1] << endl;
		}
	}
	return 0;
}
