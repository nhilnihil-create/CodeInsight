/*input
4 10
1 2
2 1
1 2
2 1
1 2
1 3
1 4
2 3
2 4
3 4
*/
 

//this ufds implementation is for this problem: https://atcoder.jp/contests/abc177/tasks/abc177_d
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <climits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
 
using namespace std;
 
/*******  All Required define Pre-Processors and typedef Constants *******/
#define ar array
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define tests int r; cin >> r; while(r--)
#define MP make_pair
#define PI acos(-1)
typedef pair<long long, long long> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define godspeed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
 
#define M(x) ((x)%(1000000007))
 
int link[200020];
int siz[200020];


int find(int x){
	while(x!=link[x]) x = link[x];
	return x;
}

bool same(int a, int b){
	return find(a)==find(b);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if(siz[a]<siz[b]){
		swap(a,b);
	}
	siz[a]+=siz[b];
	link[b]=a;
}





 
int main() {
	int n;
	int m;

	memset(link,0,sizeof(link));
	memset(siz,0,sizeof(siz));
	cin>>n>>m;

	for(int i = 1; i<=n;i++){
		link[i] = i;
	}
	for(int i = 1; i<=n; i++){
		siz[i] = 1;
	}
	rep(i,m){
		int a;
		int b;
		cin>>a>>b;
		if(!same(a,b)){
			unite(a,b);
		}
		
	}

	int mi = 0;
	for(int i = 1; i<=n;i++){

		mi = max(mi,siz[i]);
	}
	cout<<mi<<endl;;





}