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
#include <iomanip>
#include <cmath>
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100;
int main(){
	map<string,int> ma;
	ma["SAT"]=1;
	ma["FRI"]=2;
	ma["THU"]=3;
	ma["WED"]=4;
	ma["TUE"]=5;
	ma["MON"]=6;
	ma["SUN"]=7;
	string s;cin>>s;
	cout<<ma[s]<<"\n";
	return 0;
}