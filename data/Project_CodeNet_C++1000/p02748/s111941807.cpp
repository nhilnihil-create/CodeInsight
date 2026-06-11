#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <numeric>
#include <iomanip>
#include <fstream>
using namespace std;
double pie=3.14159265358979;
long long mod=998244353;
//
int main(){
	int a,b,m;
	int A[100000];
	int B[100000];
	cin>>a>>b>>m;
	int ma=1e9+7;
	int mb=1e9+7;
	for(int i=0;i<a;i++){
		cin>>A[i];
		ma=min(ma,A[i]);
	}
	for(int i=0;i<b;i++){
		cin>>B[i];
		mb=min(mb,B[i]);
	}
	int ans=ma+mb;
	for(int i=0;i<m;i++){
		int x,y,c;
		cin>>x>>y>>c;
		x--;y--;
		ans=min(ans,A[x]+B[y]-c);
	}
	cout<<ans<<endl;
	return 0;
}