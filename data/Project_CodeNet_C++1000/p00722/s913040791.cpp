
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1141&lang=jp

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<numeric>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

#define PRIME_MAX 1000000

using namespace std;

int main() {

	int A, D, N;

	bool is_prime[PRIME_MAX];

	is_prime[0] = false;
	is_prime[1] = false;
	REP(i,2,PRIME_MAX) is_prime[i] = true;
	REP(i,2,PRIME_MAX) {
		if (is_prime[i]) {
				for (int j=i+i; j<PRIME_MAX; j+=i) is_prime[j] = false;
		}
	}

	while(cin >> A >> D >> N)
	{
		if(A == 0 && D == 0 && N == 0){ break; }
		
		int nth = A;
		int count = 0;
	
		for(int d=0; d<PRIME_MAX; d+=D)
		{
			if(is_prime[nth]){ count++; }
			if(count == N){ break; }
			nth += D;
		}

		cout << nth << endl;
	}

	return 0;
}