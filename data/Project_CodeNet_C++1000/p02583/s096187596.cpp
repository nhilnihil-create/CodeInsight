#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void max_self(int &a, int b){ a = max(a, b);}
void min_self(int &a, int b){ a = min(a, b);}

void solve(){
	int n; cin>>n;
	vector< int > l(n);
	for(int &i : l) cin>>i;
	sort(l.begin(), l.end());
	int cnt = 0;
	for(int i = 0; i<n; i++){
		for(int j = i + 1; j<n; j++){
			for(int k = j + 1; k<n; k++){
				if(l[i] != l[j] && l[j] != l[k]) if(l[i] + l[j] > l[k]) cnt++;
			}
		}
	}
	cout<<cnt<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
