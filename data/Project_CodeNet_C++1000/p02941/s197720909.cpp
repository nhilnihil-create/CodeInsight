////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>
//#include <chrono>
//#include <random>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

const int N = 2e5;
int A[N + 5], B[N + 5];
LL tot = 0;

void hora(int tc) {
	int n;
	cin>>n;
	for(int i = 0;i < n;i++) cin>>A[i];
	for(int i = 0;i < n;i++) cin>>B[i];
	queue<int> q;
	for(int i = 0;i < n;i++) {
		if(B[i] > B[(i + 1) % n] + B[(i + n - 1) % n]) q.push(i);
	}
	while(!q.empty()) {
		int i = q.front();
		q.pop();
		if(B[i] <= B[(i + 1) % n] + B[(i + n - 1) % n]) continue;
		int bawah = A[i];
		int diff = B[i] - bawah;
		int ctr = diff / (B[(i + 1) % n] + B[(i + n - 1) % n]);
		tot += ctr;
		B[i] -= ctr * (B[(i + 1) % n] + B[(i + n - 1) % n]);
		if(B[(i + 1) % n] > B[i] + B[(i + 2) % n]) q.push((i + 1) % n);
		if(B[(i + n - 1) % n] > B[i] + B[(i + n - 2) % n]) q.push((i + n - 1) % n);
//		for(int i = 0;i < n;i++) cout<<B[i]<<" ";
//		cout<<endl;
	}
	for(int i = 0;i < n;i++) if(A[i] != B[i]) tot = -1;
	cout<<tot<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


