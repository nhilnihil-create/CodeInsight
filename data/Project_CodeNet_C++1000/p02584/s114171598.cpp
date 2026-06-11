#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define rep(i,ra,re) for((i)=ra;(i)<(re);(i)++)
#define _rep(i,ra,re) for((i)=ra;(i)>(re);(i)--)
#define rep_(i,ra,re) for((i)=ra;(i)<=(re);(i)++)
#define _rep_(i,ra,re) for((i)=ra;(i)>=(re);(i)--)
#define put(n) cout << n << " "; 
#define puts(n) cout << n << endl;
#define pu(n) cout << n;
#define mod 1000000007


int i,j,k,l;
static const int MAX_N=10e5;
int main(void){
	long long x,k,d;cin >> x >> k >> d;
	x=(x>0?x:-x);
	if(k<=x/d){
		puts(x-k*d);
	}else{
		k=k-x/d;
		x=x%d;
		if(k%2==1){
			puts(d-x);
		}else{
			puts(x);
		}
	}
	return 0;
}
