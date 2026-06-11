#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define endl '\n'

void max_self(int &a, int b){ a = max(a, b);}
void min_self(int &a, int b){ a = min(a, b);}

int n, cnt_r; string s;

bool good(int x){
	for(int i = 0; i<cnt_r; i++){
		if(s[i] == 'W') x--;
	}
	return x >= 0;
}

void solve(){
	cin>>n;
	cin>>s;
	for(char i: s){
		if(i == 'R') cnt_r++;
	}
	int l = -1; // bad
	int r = n; // good

	while(r > l + 1){
		int mid = (l + r) / 2;
		if(good(mid)){
			r = mid;
		}else{
			l = mid;
		}
	}
	cout<<r<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
