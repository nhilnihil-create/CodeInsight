#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

#define ll long long

#define debug_message 0
#define debug if (debug_message)

#define sz(x) (int)x.size()

int i,t,j;
int r,c,a,b,mp[1005][1005];
int rcnt[1005],ccnt[1005];
bool ok;

int main() {
	scanf("%d%d%d%d",&r,&c,&a,&b);

	for (i=1; i<=b; ++i){
		for (t=1; t<=a; ++t){
			mp[i][t]=1;
		}
	}
	
	for (i=b+1; i<=r; ++i){
		for (t=a+1; t<=c; ++t){
			mp[i][t]=1;
		}
	}

//	//check
//	ok=1;
//	for (i=1; i<=r && ok; ++i) {
//		for (t=1; t<=c && ok; ++t) {
//			if ((rcnt[i]==a || c-rcnt[i]==a) &&
//			        (ccnt[t]==b && r-ccnt[t]==b)) continue;
//			        
//			else {
//				ok=0;
//				break;
//			}
//		}
//	}
//
//	if (ok==0) printf("-1\n");
//	else {
		for (i=1; i<=r; ++i) {
			for (t=1; t<=c; ++t) {
				printf("%d",mp[i][t]);
			}
			printf("\n");
		}
//	}

	return 0;
}
/*
0011
0011
0011
0011

1100
1100
0011
0011
============
0110
0110
0011
0011

1110
0011
0011
0011
*/