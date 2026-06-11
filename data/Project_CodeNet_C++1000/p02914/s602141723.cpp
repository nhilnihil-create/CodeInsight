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


void solve(long long N, std::vector<long long> A){
	LL b=0;
	for(auto a:A){
		b^=a;
		//cerr << a << ", ";
	}
	//cerr << endl;
	//cerr << b << endl;
	LL s=0;
	for(int i=60;i>=0;i--){
		LL u=1LL<<i;
		if(b&u)continue;
		//cerr << "aaa" << endl;
		for(int j=0;j<A.size();j++){
			if(A[j]&u){
				//cerr << i << ", " << j << ": " << A[j] << endl;
				if(!(s&u)){
					s^=A[j];
				}
				for(int k=j+1;k<A.size();k++){
					if(A[k]&u){
						A[k]^=A[j];
					}
				}
				A[j]=0;
				break;
			}
		}
	}
	cout << (b^s)+s << endl;
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
