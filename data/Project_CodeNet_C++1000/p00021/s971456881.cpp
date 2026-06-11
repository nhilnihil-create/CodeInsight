#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef long long ll;

int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };

int main(){
	ios::sync_with_stdio(false);

	int n;
	scanf("%d", &n);

	double a[2], b[2], c[2], d[2];
	double e=0.00000001;


	while(n--){
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a[0], &a[1], &b[0], &b[1], &c[0], &c[1], &d[0], &d[1]);

		double l1, l2;
		bool p=false;

		if((fabs(a[0]-b[0])<e)&&(fabs(c[0]-d[0])<e)){
			p=true;
		}else if((fabs(a[0]-b[0])>e)&&(fabs(c[0]-d[0])>e)){
			l1=(b[1]-a[1])/(b[0]-a[0]);
			l2=(d[1]-c[1])/(d[0]-c[0]);

			if(fabs(l2-l1)<e)	p=true;
		}

		if(p){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

}