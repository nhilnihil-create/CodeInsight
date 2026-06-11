#include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;

int main(){
	string s;
	cin >> s;
	vector<ll> a(s.size()+1);
	ll cnt=0;
	for(int i=1;i<=s.size();i++){
		if(s.at(i-1)=='<')
			cnt++;
		if(s.at(i-1)=='>')
			cnt=0;
		a[i]=cnt;
	}
	cnt=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s.at(i)=='>')
			cnt++;
		if(s.at(i)=='<')
			cnt=0;
		a[i]=max(a[i],cnt);
	}
	ll sum=0;
	for(int i=0;i<=s.size();i++){
		sum+=a[i];
	}
	cout << sum << endl;
    return 0;
}