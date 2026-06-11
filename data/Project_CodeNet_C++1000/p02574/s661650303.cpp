#include <bits/stdc++.h>
using namespace std;

bool test = true;
int tt = 1;
#define ll long long
#define all(x) x.begin(), x.end()
#define sz(s) (int)(s.size())

struct fio
{
    fio()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(10);
    }
} fio;

const int N = 1e6 + 1;
int cnt[N];

bool check(int i) {
	int j = i;
	int res = 0;
	while(j < N) {
		res+=cnt[j];
		j+=i;
	}
	return (res <= 1);
}

int _gcd(int a, int b) {
	if(a == 0) return b;
	return _gcd(b%a, a);
}
int main() 
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
    	cin >> v[i];
    }

    int g = accumulate(all(v), 0, _gcd);
    cerr << "gcd: " << g << "\n";
    if(g!=1) {
    	cout << "not coprime\n";
    	return 0;
    }
    for(int i=0; i<n; i++) cnt[v[i]]++;
    for(int i=2; i<N; i++) {
    	if(!check(i)) {
    		cout << "setwise coprime\n";
    		return 0;
    	}
    }
    cout << "pairwise coprime\n";
}