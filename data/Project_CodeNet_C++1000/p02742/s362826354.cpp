#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
//typedef __int64 LL;
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;

const int MOD=1000000007;

int main(){
	LL h,w;
	cin>>h>>w;
	if(h==1 || w==1)cout<<1<<"\n";
	else cout<<(h*w+1)/2<<"\n";	
	return 0;
}