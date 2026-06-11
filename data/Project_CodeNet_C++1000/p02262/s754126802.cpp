#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

ll insertionSort(int A[], int N, int g){
	ll c = 0;

	for (int i = g; i < N; i++){
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v){
			A[j + g] = A[j];
			j -= g;
			c++;
		}
		A[j + g] = v;
	}

	return c;
}

void shellSort(int A[], int N){

	// create G vector
	vint G;
	int h = 1;
	G.push_back(h);
	h = 3 * h + 1;
	
	while (h < N){
		G.push_back(h);
		h = 3 * h + 1;
	}

	ll ct = 0;
	RFOR(i, 0, G.size()){
		ct += insertionSort(A, N, G[i]);
	}

	cout << G.size() << endl;
	RFOR(i, 0, G.size()){ 
		cout << G[i];
		if (i > 0) cout << ' ';
	}
	cout << endl;
	cout << ct << endl;

	rep(i, N){
		cout << A[i] << endl;
	}

}

const int MAX_N = 1000000;
int A[MAX_N];

int main() {

	int N;
	cin >> N;

	rep(i, N){ cin >> A[i]; }

	shellSort(A, N);

}