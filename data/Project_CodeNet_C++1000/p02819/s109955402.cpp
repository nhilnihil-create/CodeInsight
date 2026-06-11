#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 100005
#define INF INT_MAX

#define PI   3.14159265358979323846264338327950

#define PB push_back
#define PF push_front
#define F first
#define S second

#define fixx(n) fixed << setprecision(n)

#define ll 	 long long 

#define mod  1000000007
int p[MAXX];
void sieve(){
	for(int i = 1; i < MAXX; i ++){
		p[i] = i;
	}
	for(int i = 2; i * i < MAXX; i ++){
		for(int j = i * i; j < MAXX;j += i){
			if(p[j] == j){
				p[j] = i;
			}
		}
	}
}

int main()
{
	FAST;
	sieve();
	int n;
	cin >> n;
	n--;
	while(n ++){
		if(p[n] == n){
			cout << n;
			return 0;
		}
	}
	return 0;
}