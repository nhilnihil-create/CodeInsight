#include<bits/stdc++.h>
#define SORT(v) sort(v.rbegin() , v.rend())
#define si(n) scanf( "%d" , &n)
#define sii(n , m) scanf( "%d %d" , &n , &m)
#define sl(n) scanf( "%lld" , &n)
#define sll(n , m) scanf( "%lld %lld" , &n, &m)
#define ss(cad) scanf( "%s" , cad)
#define sz(x) (int)x.size()
#define PB push_back
#define fst first
#define scn second
#define DBG(x) cerr << #x << " = " << (x) << endl
#define M 1000000007
#define N_MAX 1000010
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vp;

int cb[1000100];
void criba(){
	for(int i = 2; i*i <= 1000000; i++){
		if(cb[i])
			continue;
		for(int j = i*i; j <= 1000000; j+=i)
			if(cb[j] == 0)
				cb[j] = i;
	}
}

int vec[1001000];
bool frec[1001000];

int main(){
	criba();
	int n;
	si(n);
	int gcd = 0;
	for(int i = 0; i < n; i++){
		si(vec[i]);
		if(gcd == 0)
			gcd = vec[i];
		else
			gcd = __gcd(gcd, vec[i]);
	}
	bool sw = 1;
	for(int i = n-1; i >= 0; i--){
		int tmp = vec[i];
		while(cb[tmp] != 0){
			int f = cb[tmp];
			//cout << 
			//frec[f] = 1;
			while(tmp%f == 0){
				tmp /= f;
			}
			if(frec[f] == 0)
				frec[f] = 1;
			else
				sw = 0;
		}

		if(tmp != 1){
			//cout << tmp << endl;
			if(frec[tmp] == 0)
				frec[tmp] = 1;
			else
				sw = 0;
		}

		if(sw == 0)
			break;
	}
	if(sw)
		printf("pairwise coprime\n");
	else if(gcd == 1)
		printf("setwise coprime\n");
	else
		printf("not coprime\n");
	
    return 0;
}