#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define FOR(i,a,b) for(long long int i=(a);i<(b);i++)
#define REP(i,n) for(long long int i=0;i<(n);i++)
#define ALL(s) (s).begin(),(s).end()

#define PI 3.14159265358479

typedef long long int ll;
typedef vector<long long int> vi;

int main(){
	ll n, c = 0;
	while (cin >> n){
		REP(i, 10){
			REP(j, 10){
				REP(k, 10){
					REP(l, 10){
						if (i + j + k + l == n)c++;
					}
				}
			}
		}
		cout << c << "\n";
		c = 0;
	}
}