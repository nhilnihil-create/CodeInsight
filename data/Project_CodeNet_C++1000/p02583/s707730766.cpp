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
static const int MAX_N=10e2;
int L[MAX_N];
int main(void){
	int N;cin >> N;
	rep(i,0,N){
		cin >> L[i];
	}sort(L,L+N);
	
	int ans=0;
	_rep(i,N-1,1){
		_rep(j,i-1,0){
			if(L[i]==L[j])continue;
			_rep_(k,j-1,0){
				if(L[i]>=L[j]+L[k])
					break;
				else if(L[i]==L[k] || L[j]==L[k])continue;
				ans++;
			}
		}
	}puts(ans);
	return 0;
}
