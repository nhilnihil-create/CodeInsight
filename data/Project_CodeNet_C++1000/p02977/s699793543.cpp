#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define FIND(x, target) find(x.begin(),x.end(),target)
#define pb(x) push_back(x)
#define output(x) cout<<x<<endl
#define ERASE(x, n) erase(x.begin(), x.begin+n)
// #define int long long
#define P pair<int, int>
typedef long long ll;

const long long int MOD = 1e9+7;
const int INF = -1;

signed main(void) {
  	int N;
  	cin >> N;
  	if (N <= 2) {
  		cout << "No" << endl;
  	} else {
  		int remain = N-3;
  		bool even = false;
  		if (remain%2 == 0) {
  			even = true;
  		}
  		bool find = true;

  		if (even == false) {
  			find = false;
  			for (int i=2; i<N; i++) {
  				int a = int(i^1^N);
  				if (2<=a && a<N) {
  					int b = i;
  					if (b%2==0) { b+=N;}
  					if (a%2==0) { a+=N;}
  					cout << "Yes" << endl;
  					cout << N << " " << a << endl;
  					// cout << a << " " << N+1 << endl;
  					// cout << N+1 << " " << b << endl;
  					cout << b << " " << N*2 << endl;
  					find = true;
  					break;
  				}
  			}	
  		} else {
  			cout << "Yes" << endl;
  		}

  		if (find) {
  			cout << "1 2" << endl;
	  		cout << "2 3" << endl;
	  		cout << "3 " << N+1 << endl;
	  		cout << N+1 << " " << N+2 << endl;
	  		cout << N+2 << " " << N+3 << endl;

	  		rep(i, remain/2) {
	  			cout << i*2+4 << " " << i*2+5 << endl;
	  			cout << i*2+5 << " " << N+1 << endl;
	  			cout << N+1 << " " << i*2+4+N << endl;
	  			cout << i*2+4+N << " " << i*2+5+N << endl;
	  		}
  		} else {
  			cout << "No" << endl;
  		}
  	}
 	
	return 0;
}
