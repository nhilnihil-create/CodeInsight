#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <stack>
#include <limits.h>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int Gcd(int a,int b){if (b == 0) return a; return Gcd(b , a%b);}
int Lcm(int a, int b){ return a/Gcd(a,b)*b;}
inline int read(){
	int f = 1, x = 0;char ch = getchar();
	while (ch > '9' || ch < '0'){if (ch == '-')f = -f;ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}
const int maxn = 1e6 + 10;
struct node{
	double x,y;
}p[maxn];
double xx,yy;
int cmp(node a,node b){
    if (atan2(a.y - yy, a.x - xx) != atan2(b.y - yy, b.x - xx))
        return (atan2(a.y - yy, a.x - xx)) < (atan2(b.y - yy, b.x - xx));
    return a.x < b.x;
}
int main(){
	int n = read();
	for(int i=1; i<=n; i++){
		p[i].x = read();
		p[i].y = read();
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1; i<=n; i++){
		p[i+n] = p[i]; 
	}
	double ans = 0;
	for(int i=1; i<=n; i++){
		xx = yy = 0;
		for(int j=i; j<i+n; j++){
			xx += p[j].x;
			yy += p[j].y;
			ans = max(ans,sqrt(xx*xx+yy*yy));
		}
	}
	printf("%.11f\n",ans);
	return 0;
}