#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
    int N;
    cin >> N;
    int P[N];
    int Q[N];
    int ord[N];
    rep(i,N) {
	cin >> P[i];
	ord[i] = i+1;
    }
    rep(i,N) {
	cin >> Q[i];
    }

    int a,b;
    int cnt = 0;
    do {
	bool fa = true;
	bool fb = true;
	
	rep(i,N) {
	    if(ord[i] != P[i]) fa = false;
	    if(ord[i] != Q[i]) fb = false;
	}
	if(fa) a = cnt;
	if(fb) b = cnt;
	cnt++;

	// for(auto itr : ord) cout << itr ;
	// cout << endl;
	// cout << cnt << endl;
    }while(next_permutation(ord,ord+N));

    cout << abs(a-b) << endl;
    
    return 0;
}

