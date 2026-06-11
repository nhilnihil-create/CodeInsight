#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()

#define PI acos(-1.0)
#define INF 1000000007

typedef long long ll; 
typedef pair<ll, ll> P;
typedef pair<string, ll> PS;


ll n, a[100], C = 0, B = 0;

int main(){
	cin >> n;
	REP(i, n){
		C = 0, B = 0;
		REP(j, 10)cin >> a[j];
		REP(j, 10){
			if (a[j] > B){
				B = a[j];
			}
			else if (a[j] > C){
				C = a[j];
			}
			else{
				cout << "NO\n";
				break;
			}
			if (j == 9){
				cout << "YES\n";
			}
		}
	}
}