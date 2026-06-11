//q016.cpp
//Sun Aug  9 13:22:38 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	int a[n];
	rep(i,n) a[i]=i+1;

	int p[n],q[n];
	rep(i,n){
		cin >> p[i];
	}
	rep(i,n){
		cin >> q[i];
	}

	int count = 0;
	int pp=0;
	int qq=0;
	do {
		if (pp==0){
			int flag = 1;
			rep(i,n){
				if (a[i]!=p[i]){
					flag = 0;
					break;
				}
			}
			if(flag){
				pp=count;
			}
		}
		if (qq==0){
			int flag = 1;
			rep(i,n){
				if (a[i]!=q[i]){
					flag = 0;
					break;
				}
			}
			if(flag){
				qq=count;
			}
		}
		count++;
	} while (next_permutation(a,a+n)); //必ずaを事前にソート


	cout << abs(pp-qq) << endl;
//	printf("%.4f\n",ans);
}