#include <bits/stdc++.h>
#define pq priority_queue
using namespace std; typedef pair<int, int> P; typedef pair<int, P> P2;
typedef pair<int, P2> P3; typedef long long ll; typedef long double ld;
constexpr long long gcd(long long a, long long b){return b ? gcd(b, a % b) : a;}
constexpr long long lcm(long long a, long long b){return a / gcd(a, b) * b;}
constexpr int INF = 1e9, MOD = INF + 7, around[] = {0, 1, 1, -1, -1, 0, -1, 1, 0, 0};
constexpr int mod_pow(long long x, long long n, const int mod){long long ret=1;while(n){if(n&1)(ret*=x)%=mod;(x*=x)%=mod;n>>=1;}return ret;}
template<int n> struct Prime{bool arr[n+1];constexpr bool operator[](int k){return arr[k];}constexpr Prime():arr(){for(int i=2;i<n;i++){arr[i]=true;for(int j=2;j*j<=i;j++){if(!(i%j))arr[i]=false;}}}};
template<int n> struct Factorial{long long arr[n+1],ary[n+1];constexpr Factorial():arr(),ary(){arr[0]=1;ary[0]=1;for(int i=0;i<n;i++){arr[i+1]=arr[i]*(i+1)%MOD;ary[i+1]=mod_pow(arr[i+1],MOD-2,MOD);}}};
constexpr Factorial<10> fact; constexpr Prime<10> prime;
constexpr int comb(int a, int b){long long pos = fact.arr[a], pot = fact.ary[a - b], por = fact.ary[b];return pos * pot % MOD * por % MOD;}
template<int n> struct Bernoulli{long long arr[n+1];constexpr Bernoulli():arr(){arr[0]=1;for(int i=1;i<=n;i++){long long sum=0;for(int j=0;j<i;j++){(sum+=comb(i+1,j)*arr[j]%MOD)%=MOD;}arr[i]=(MOD-mod_pow(i+1,MOD-2,MOD))%MOD*sum%MOD;}}};
constexpr int vx[] = {1, 0, -1, 0}, vy[] = {0, 1, 0, -1};
constexpr int sqrtN = 512, logN = 32;
constexpr ld PI = abs(acos(-1));
constexpr ll LINF=1e18;

int w, h, a[55][55];

int main(){
	while(cin >> w >> h,w){
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> a[i][j];
			}
		}
		
		int c = 0;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(a[i][j] != 1) continue; c++;
				
				queue<P> qu; qu.push({i, j}); a[i][j] = 2;
				while(!qu.empty()){
					auto p = qu.front(); qu.pop();
					
					for(int k = 0; k < 8;){
						int nx = p.first + around[k], ny = p.second + around[++k];
						if(nx<0||ny<0||nx>=h||ny>=w||a[nx][ny] != 1) continue;
						a[nx][ny] = 2;
						qu.push({nx, ny});
					}
				}
			}
		}
		
		cout << c << endl;
	}

	return 0;
}

