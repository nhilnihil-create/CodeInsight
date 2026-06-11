#include<iostream>
#include<vector>
#include<algorithm>
#define loop(i, n) for(i=0; i<n; i++)
#define pb push_back
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> p;
	int i, mint = 200007;
	for(i=0; i<n; i++){
		int x;
		cin >> x;
		p.pb(x);
	}
	int count = 0;
	for(i=0; i<n; i++){
		if(p[i]<=mint){
			count++;
			mint = p[i];
		}
	}
	cout << count << endl;
	return 0;
}
