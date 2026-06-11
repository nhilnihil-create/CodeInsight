#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
#define MOD 1000000007 
#define mx 200003

long long n, a[mx], b[mx];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	queue<int> bisa;
	for(int j = 0; j < n; j++){
		int i = (j - 1 + n) % n;
		int k = (j + 1) % n;
		if(b[j] > b[i] + b[k] && b[j] > a[j])
			bisa.push(j);
		if(b[j] < a[j]){
			cout << -1 << '\n';
			return 0;
		}
	}
	long long jaw = 0;
	// debug(sz(bisa));
	// debug(bisa.front());
	while(1){
		// for(int i = 0; i < n; i++)
			// cout << b[i] << ' ';
		// cout << '\n';
		if(bisa.empty())
			break;
		int j = bisa.front();
		bisa.pop();
		// debug(j);
		int i = (j - 1 + n) % n;
		int k = (j + 1) % n;
		if(a[j] >= b[i] + b[k]){
			if((b[j] - a[j]) % (b[i] + b[k]) > 0){
				cout << -1 << '\n';
				return 0;
			}
			jaw += (b[j] - a[j]) / (b[i] + b[k]);
			b[j] = a[j];
		}
		else{
			long long sisa = b[j] % (b[i] + b[k]);
			if(sisa < a[j]){
				cout << -1 << '\n';
				return 0;
			}
			jaw += b[j] / (b[i] + b[k]);
			b[j] = sisa;
		}
		if(b[i] > (b[(i - 1 + n) % n] + b[(i + 1) % n]) && b[i] > a[i])
			bisa.push(i);
		if(b[k] > (b[(k - 1 + n) % n] + b[(k + 1) % n]) && b[k] > a[k])
			bisa.push(k);
	}
	for(int i = 0; i < n; i++){
		if(b[i] != a[i]){
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << jaw << '\n';
}
