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
int a[10];
int main(){
	for(int i=1;i<=5;i++)cin>>a[i];
	for(int i=1;i<=5;i++)if(a[i]==0){cout<<i<<endl;break;}
    return 0;
}
