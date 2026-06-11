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
	int x;
	cin>>x;
	int a=((x/10)%10)*10+x%10;
	if(5*(x/100)>=a)cout<<1;
	else cout<<0;
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