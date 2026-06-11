#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <string>
#include <algorithm>
#include <string>
#include <climits>
#include <utility>

#define REP(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define REG(i, a, b) for (int (i) = ((int)(a)); (i) < ((int)(b)); i++)
#define ALL(V) (V).begin(), (V).end()
#define PRINT(STR) cout << (STR) << endl
#define ROUNDED(N) fixed << setprecision(N)
#define SPACE " "

typedef long long ll;
using namespace std;

int nextInt() { int n; cin >> n; return n; }
double nextDouble() { double d; cin >> d; return d; }
string nextString() { string str; cin >> str; return str; }

int main() {
	cin.tie(0); //?????±?????????????????????
	ios::sync_with_stdio(false); //printf??¨??±??????????????????

	int h,w;
	while(cin>>h>>w,h){
		int max_w = sqrt(w*w + h*h);
		int ans = 10000000;
		int ans_h,ans_w;
		int def = h*h+w*w;
		for(int i = sqrt((w*w + h*h)/2);i<max_w+2;i++){
			for(int j = 1;j<i;j++){
				if((def<i*i+j*j||def==i*i+j*j&&j>h)&&ans>=i*i+j*j){
					ans = i*i+j*j;
					ans_h = j;
					ans_w = i;
				}
			}
		}
		cout << ans_h << " " << ans_w  << endl;
	}
	return 0;
}