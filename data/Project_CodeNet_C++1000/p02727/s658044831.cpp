#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL X, Y, A, B ,C;
	cin >> X >> Y >> A >> B >> C;

	vector<LL> P, Q, R;
	for(int i=0; i<A; i++){ LL p; cin >> p; P.push_back(p); }
	for(int i=0; i<B; i++){ LL q; cin >> q; Q.push_back(q); }
	for(int i=0; i<C; i++){ LL r; cin >> r; R.push_back(r); }

	sort(P.begin(), P.end(), std::greater<LL>() );
	sort(Q.begin(), Q.end(), std::greater<LL>() );
	sort(R.begin(), R.end(), std::greater<LL>() );

	vector<LL> T;

	//Pの中で上位X個をTに入れる
	for(int i=0; i<X; i++){
		T.push_back(P[i]);
	}
	//Qの中で上位X個をTに入れる
	for(int i=0; i<Y; i++){
		T.push_back(Q[i]);
	}
	//RはすべてTに入れる。
	for(int i=0; i<R.size(); i++){
		T.push_back(R[i]);
	}

	sort(T.begin(), T.end(), std::greater<LL>() );

	//上位X+Y個を取り出す
	LL ans = 0;
	for(int i=0; i<X+Y; i++){
		ans += T[i];
	}
	printf("%lld\n", ans);
	return 0;
}

