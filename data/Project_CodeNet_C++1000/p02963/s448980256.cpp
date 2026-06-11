#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

#define int ll

const int INF = 1e9;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int s;cin >> s;
	cout << "0 0 ";
	if(s<=INF){
		cout << s << " 0 0 1" << "\n";
		return 0;
	}
	int l=0, r=INF+100;
	while(r-l>1){
		int mid = (l + r)/2;
		if(mid*mid <= s)
			l = mid;
		else
			r = mid;
	}
	int sq = l;
	if(sq*sq == s){
		cout << sq << " 0 0 " << sq << "\n";
		return 0;
	}
	if((sq+1)*sq >= s){
		cout << sq+1 << " 1 " << (sq+1)*sq-s << " " << sq << "\n";
		return 0;
	}
	cout << sq+1 << " 1 " << (sq+1)*(sq+1)-s << " " << sq+1 << "\n";
 	return 0;
}














