#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int a,b,c,m,cnt;
int main(){
	cin>>a>>b>>c>>m;
	while(b<=a)b<<=1,cnt++;
	while(c<=b)c<<=1,cnt++;
	cout<<(cnt>m?"No\n":"Yes\n");
	return 0;
}
