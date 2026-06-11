#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <random>

using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
long A[500];
long M[500];
bool OK(long x,int N,int K){
	for(int i=0;i<N;i++){
		M[i] = A[i] % x;
	}
	sort(M,M+N);
	int p = 0;
	int q = N-1;
	long ans = 0;
	while(p < q){
		if(M[q]+M[p] <= x){
			ans += M[p];
			M[q] += M[p];
			p++;
		}
		else{
			ans += x - M[q];
			M[p] -= x - M[q];
			q--;
		}
	}
	return ans <= K;
}
void Calc(){
	int N = rei();
	long K = rei();
	long sum = 0;
	for(int i=0;i<N;i++){
		A[i] = rei();
		sum += A[i];
	}
	long ans = 0;
	for(long i=1;i*i<=sum;i++){
		if(sum % i == 0){
			if(OK(i,N,K)){
				ans = max(ans,i);
			}
			if(OK(sum/i,N,K)){
				ans = max(ans,sum/i);
			}
		}
	}
	cout << ans << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}