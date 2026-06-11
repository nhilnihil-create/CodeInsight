#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(a) cerr << #a << ": " << a << endl
#define sz(a) int(a.size())
#define rep(i,n) for(int i=0;i<n;i++)
#define forr(i, st, en) for(int i = st; i <= en; i++)
#define all(v) (v).begin(),(v).end()
#define X first
#define Y second
#define pb push_back
#define fast cin.tie(0); ios::sync_with_stdio(false)
#define vi vector<int>
#define vii vector<vector<int>>
#define int long long
int32_t main(){ fast;
	int n; cin>>n;
	vi a(n);
	rep(i, n){
		cin>>a[i];
	}
	sort(all(a));
	int answer = 0;
	for(int i = 0; i < n - 2; i++){
		for(int j = i + 1; j < n - 1; j++){
			for(int k = j + 1; k < n; k++){
				if(a[i] != a[j] && a[j] != a[k] && a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[j] + a[k] > a[i]){
					answer++;
				}
			}
		}
	}
	cout<<answer<<endl;
}
