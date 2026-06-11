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
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;

const string YES = "Yes";
const string NO = "No";

void solve(long long N){
	int u=1;
	while(u*2<=N){
		u*=2;
	}
	if(N==u){
		cout << NO << endl;
		return;
	}

	cout << YES << endl;
	int v=N;
	if(v%2==0){
		v--;
	}
	if(N%2){
		for(int i=2;i<=N;i++){
			cout << 1 << " " << i << endl;
			cout << i << " " << (i^1)+N << endl;
		}
		cout << N+1 << " " << N+2 << endl;
		return;
	}
	for(int i=2;i<N;i++){
		cout << 1 << " " << i << endl;
		cout << i << " " << (i^1)+N << endl;
	}
	cout << N+1 << " " <<  N+2 << endl;
	cout << N << " " << (N^u) << endl;
	cout << 2*N << " " << (u^1) << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
