#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

int a[1010101];
int b[1010101];

int main(){
	fill(a ,a + 1010101,1e9);
	fill(b,b + 1010101,1e9);
	a[0] = 0;
	b[0] = 0;

	int MAX = 1e6;

	for(int i = 1;i <= MAX;i++){
		int temp;
		for(int j = 1;(temp = (j) * (j + 1) * (j + 2) / 6) <= i;j++){
			a[i] = min(a[i] , a[i - temp] + 1);
			if(temp % 2 == 1)
				b[i] = min(b[i] , b[i - temp] + 1);
		}
	}

	int n;
	while(cin >> n , n){
		cout << a[n] << " " << b[n] << endl;
	}
}

