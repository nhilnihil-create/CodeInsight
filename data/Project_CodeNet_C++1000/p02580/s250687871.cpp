#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n , m , k , rMax , cMax , r[N] , c[N] , R , C , cnt;
vector < pair< int , int > > pot;

int main(){
	scanf("%d %d %d" , &n , &m , &k);
	for(int x , y , i = 1; i <= k; i++){
		scanf("%d %d" , &x , &y) , pot.push_back({x , y});
		rMax = max(rMax , ++r[x]) , cMax = max(cMax , ++c[y]);
	}
	for(int i = 1; i <= m; i++) C += c[i] == cMax;
	for(int i = 1; i <= n; i++) R += r[i] == rMax;
	for(int i = 0; i < k; i++)
		cnt += r[pot[i].first] == rMax && c[pot[i].second] == cMax;
	printf("%d" , rMax + cMax - (cnt == 1ll * R * C));
	return 0;
}