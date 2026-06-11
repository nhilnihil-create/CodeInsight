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
int x;
int main(){
	cin>>x;
	if(x>1799)cout<<1<<endl;
	else if(x>1599)cout<<2<<endl;
	else if(x>1399)cout<<3<<endl;
	else if(x>1199)cout<<4<<endl;
	else if(x>999)cout<<5<<endl;
	else if(x>799)cout<<6<<endl;
	else if(x>599)cout<<7<<endl;
	else cout<<8<<endl;
	return 0;
}
