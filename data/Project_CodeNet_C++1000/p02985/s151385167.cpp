#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

const int mod = 1000000007;
 
using namespace std;
typedef long long ll;

ll calc(vector<int> v[], int parent, int node, int level, int K, int bro){
	ll value;
	int color = level == 0 ? K : level == 1 ? K-1 : K-2;
	color -= bro;
	
	value = color;
	int count = 0;
	for(int i = 0; i < v[node].size(); i++){
		if(v[node][i] != parent){
			value = (value * calc(v, node, v[node][i], level+1, K, count)) % mod;
			count++;
		}
	}

	return value;
}

int main()
{
	int N, K;
	vector<int> v[100000];
	
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	
	ll ans = calc(v, -1, 0, 0, K, 0);
	
	printf("%lld\n", ans);
	
	return 0;
}