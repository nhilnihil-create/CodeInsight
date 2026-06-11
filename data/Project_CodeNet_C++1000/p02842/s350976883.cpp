# include <bits/stdc++.h>
# define sz(x) (int)((x).size())
# define F first
# define S second
# define pb push_back
# define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5e5+5;

void solve(){
	int n;
	cin>>n;
	int x=ceil(n*1.0/1.08);
	int j=x*1.08;
	//cerr<<j<<' '<<x<<' ';
	if(j==n)cout<<x<<' ';
	else cout<<":(";
}

int main(){
	ios_base :: sync_with_stdio(false);
	int test = 1; 
	//cin >> test;	
	while (test--){
		solve();
	}
	return 0;
}