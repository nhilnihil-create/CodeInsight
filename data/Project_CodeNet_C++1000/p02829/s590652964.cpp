#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 500005
#define INF INT_MAX

#define PI   3.14159265358979323846264338327950

#define PB push_back
#define PF push_front
#define F first
#define S second

#define fixx(n) fixed << setprecision(n)

#define ll 	 long long

#define mod  1000000007

map<int, bool> m;

int main()
{
	FAST;
	int a, b;
	cin >> a >> b;
	m[a] = true;
	m[b] = true;
	for(int i = 1; i <= 3; i ++){
		if(!m[i]){
			cout << i;
			return 0;
		}
	}
	
	return 0;
}