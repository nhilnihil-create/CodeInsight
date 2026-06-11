#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define F first
#define S second

#define ONLINE_JUDGE 1

using namespace std;

const int mod = 1e9+7;
const int MAX = 100001;

void pr(vector<int> v){
	for(int x : v){
		cout << x << " ";
	}
	cout << "\n";
}

void solve(){
	int n,k,c;
	cin >> n >> k >> c;
	string s; cin >> s;
	vector<int> lf(n);
	vector<int> rt(n);
	int t = 1;
	int p = -MAX;	
	for(int i = 0; i < n; i++){
		if(s[i]=='o'){
			int d = i-p;
			if(d > c){
				lf[i] = t++;
				p = i;
			}
			if(t > k) break;
		}
	}
	reverse(s.begin(), s.end());
	t = k;
	p = -MAX;	
	for(int i = 0; i < n; i++){
		if(s[i]=='o'){
			int d = i-p;
			if(d > c){
				rt[i] = t--;
				p = i;
			}
			//if(t > k) break;
		}
	}
	reverse(rt.begin(), rt.end());
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(rt[i]==lf[i] && rt[i] > 0){
			cout << i + 1 << "\n";
		}
	}
}
int main(){
	#ifndef ONLINE_JUDGE	
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);		
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}