// E - Coprime
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rpd(i,s,e,d) for(int i=(s);i<(int)(e);i+=(d))

int gcd_all(vi &A){ int g = 0; for(int a:A) g = gcd(g, a); return g; }

int sum_array(vi &C, int start, int end, int step){
	int c = 0;
	rpd(i, start, end, step) c += C[i];
	return c;
}

bool is_pairwise(vi &A){
	int MAX_A = 1000000 + 1;
	vi C(MAX_A, 0); for(int a:A) C[a]++;
	if(sum_array(C, 2, MAX_A, 2) > 1) return false;
	rpd(i, 3, MAX_A, 2) if(sum_array(C, i, MAX_A, i) > 1) return false;
	return true;
}

int solve(vi &A){
	if(is_pairwise(A)) return 0;
	if(gcd_all(A) == 1) return 1;
	return 2;
}

int main(){
	int N; cin>>N;
	vi A(N); for(auto& a:A) cin>>a;
	cout<< vector<string>{"pairwise","setwise","not"}[solve(A)] <<" coprime\n";
}
