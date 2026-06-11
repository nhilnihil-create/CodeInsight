#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
using namespace std;

long long fac(int n){
	long long ret = 1;
	for(int x=2;x<=n;++x)ret *= x;
	return ret;
}

int main(){
	int n;
	while(scanf("%d",&n)==1){
		cout<<fac(n)<<endl;
	}
	return 0;
}