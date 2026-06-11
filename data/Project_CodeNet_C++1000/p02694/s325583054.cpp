#include<bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)
#define forr(i,a,n) for(int i = a; i<= n; i++)
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(u) u.begin(),u.end()
#define lli long long int
#define ld long double

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vi> vvi;

lli n;
lli act = 100;
int days = 0;
int main(){__
	cin >> n;
	while(act < n){
		act += act/100;
		days++;
	}
	cout << days << '\n';
	return 0;
}

