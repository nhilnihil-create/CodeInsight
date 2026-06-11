#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	cin.tie(0);	
	cout.tie(0);	
	ios_base::sync_with_stdio(0);
	ll ta,tb,af,ab,bf,bb;
	cin >> ta >> tb >> af >> ab >> bf >> bb;
	af *= ta;
	bf *= ta;
	ab *= tb;
	bb *= tb;
	if(af + ab == bf + bb){
		cout << "infinity" << '\n';
	}
	else{
		if(af + ab > bf + bb){
			swap(af,bf);
			swap(ab,bb);
		}
		if(af < bf){
			cout << 0 << '\n';
		}
		else{
			ll k = (af-bf)/(bf + bb - af - ab);
			ll cor = k * (bf + bb - af - ab) == af - bf;
			cout << 2*(k + 1) - 1 - cor << '\n'; 
		}
	}
}
