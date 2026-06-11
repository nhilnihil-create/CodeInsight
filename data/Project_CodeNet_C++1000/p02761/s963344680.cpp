#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void max_self(int &a, int b){ a = max(a, b);}
void min_self(int &a, int b){ a = min(a, b);}

void solve(){
	int n, m; cin>>n>>m;
	vector< int > s(m), c(m);
	for(int i = 0; i<m; i++){
		cin>>s[i]>>c[i];
		s[i]--;
	}
	for(int i = 0; i<1000; i++){
		bool ok = 1;
		vector< int > num;
		int x = i;
		while(x){
			num.push_back(x%10);
			x /= 10;
		}
		if(i == 0) num.push_back(0);
		reverse(num.begin(), num.end());
		for(int j = 0; j<m; j++){
			if(num[s[j]] != c[j]) ok = 0;
		}
		if(n != 1 && (0 <= i && i <= 9)) ok = 0;
		else if(n != 2 && (10 <= i && i <= 99)) ok = 0;
		else if(n != 3 && (100 <= i && i <= 999)) ok = 0;
		if(ok){
			cout<<i<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
