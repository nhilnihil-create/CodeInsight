#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
#define FOR(i,n) for(i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	int a[4],b[4];
	for(;cin>>a[0]>>a[1]>>a[2]>>a[3]>>b[0]>>b[1]>>b[2]>>b[3];){
		int x=0,y=0;
		rep(i,4)if(a[i]==b[i])x++;
		rep(i,4)rep(j,4)if(i!=j&&a[i]==b[j])y++;
		printf("%d %d\n",x,y);
	}
	return 0;
}