#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;
const int mod = MOD7;

void ERROR(int num) { cout << "ERROR" << num << endl; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N;
	cin >> N;
	vector<double> A(N), B(N);
	rep(i,N) cin >> A[i] >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int num;
	if(N%2==1){
		int range = B[N/2] - A[N/2];
		num = range;
	}else{
		double meanB = (B[(N-1)/2] + B[(N-1)/2+1])/2;
		double meanA = (A[(N-1)/2] + A[(N-1)/2+1])/2;
		double range = meanB - meanA;
		num = range/0.5;
	}

	cout << num+1 << endl;
}
