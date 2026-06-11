#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>
using namespace std;
typedef long long LL;

const int L=3e5+1;
LL D[L];
LL U[L];
LL V[L];

void solve(long long N, std::vector<long long> A){
	sort(A.begin(),A.end());
	int k=1;
	vector<int> cs,ds;
	for(int i=1;i<N;i++){
		if(A[i]==A[i-1]){
			k++;
		}
		else{
			D[k]++;
			k=1;
		}
	}
	D[k]++;
	for(int i=1;i<=N;i++){
		//cerr << i << ", " << D[i] << endl;
		U[i]=U[i-1]+i*D[i];
		V[i]=V[i-1]+D[i];
	}
	vector<LL> r;
	r.push_back(N+1);
	for(int i=1;i<=N;i++){
		r.push_back((U[i]+i*(V[N]-V[i]))/i);
		//cerr << i << ": " << r.back() << endl;
	}
	int v=N;
	for(int i=1;i<=N;i++){
		while(i>r[v])
		{
			v--;
		}
		printf("%d\n",v);
	}
}


int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}


