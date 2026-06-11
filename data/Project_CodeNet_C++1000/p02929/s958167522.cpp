#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = (long long)1e9 + 7; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}



signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N, ans = 1;
	string s;
	
	cin>>N;
	
	cin>>s;
	
	for(int i = 0; i < 2*N; i++){
		if(s[i] == 'B'){
			if(i%2) s[i] = 'R';
			else s[i] = 'L';
		} else {
			if(i%2) s[i] = 'L';
			else s[i] = 'R';
		}
	}
	// cout<<s<<endl;
	
	if(count(s.begin(), s.end(), 'L') != N){
		cout<<0<<endl;
		return 0;
	}
	
	for(int i = 0, con = 0; i < 2*N; i++){
		if(s[i] == 'R'){
			ans *= con;
			ans %= MOD;
			con--;
		} else {
			con++;
		}
	}

	for(int i = 1; i <= N; i++){
		ans *= i;
		ans %= MOD;
	}
	
	cout<<ans<<endl;
	
	return 0;
}