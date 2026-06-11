#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first 
#define se second
#define mst(x,y) memset(x,y,sizeof(x))

typedef pair<int,int> pii;
typedef long long ll;
typedef double db;
const ll INF = 0x7fffffff;
const db eps = 1e-5;
const ll mod = 1e9+7;
const int MAXN = 100010;
int MIN(int a, int b) {return a>b?b:a;}
int main() {
	ios_base::sync_with_stdio(0);
	int n,m,x=0;
	char a[MAXN];
	cin>>n>>m>>a;
	x += (a[0] == 'R' && a[1] == 'R')+(a[n-1] == 'L' && a[n-2] == 'L');
	for (int i=1;i<n-1;i++) {
		x += (a[i]=='L' && a[i-1] != 'R') + (a[i] == 'R' && a[i+1] != 'L');
	}
	cout<<MIN(n-1,x+2*m)<<endl;
	return 0;
}