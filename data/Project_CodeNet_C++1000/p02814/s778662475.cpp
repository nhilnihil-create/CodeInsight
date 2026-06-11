#include<bits/stdc++.h>
#define endl "\n"
#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cout<<#x<<" : {"<<x<<"}"<<endl;
#endif
using namespace std;
typedef long long int lli;
inline lli binexp(lli a, lli b, lli m){
	lli res = 1LL;
	while(b != 0){
		if(b & 1){
			res *= a;
			if(res > m)
				return -1LL;
			b--;
		}
		else{
			a = a * a;
			b /= 2;
		}
	}
	return res;
}

 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i=0; i<n; ++i)	cin >> v[i];
	int factors = 0;
	bool possible = true;
	for(int i=0; i<n; ++i){
		int ele = v[i]/2;
		if(!possible)	break;
		if(ele%2 == 0){
			int cnt = 0;
			while(ele%2 == 0){
				cnt++;
				ele /= 2;
			}
			if(i != 0 && cnt != factors){
				possible = false;
				break;
			}
			factors = cnt;
		}
	}
	if(!possible){
		cout << 0 << endl;
		return 0;
	}
	lli prod = 1LL;
	
	if(!possible)
		cout << 0 << endl;
	else{
		lli l = (lli)v[0]/2;
		for(int i=1; i<n; ++i){
			l = (l * (v[i]/2)) / (__gcd(l, (lli)v[i]/2));
			if(l > m){
				possible = false;
				break;
			}
		}
		if(!possible){
			cout << 0 << endl;
		}
		else{
			lli num = m / (int)l;
			cout << (num + 1)/2 << endl;			
		}

	}
	
	return 0;
}
