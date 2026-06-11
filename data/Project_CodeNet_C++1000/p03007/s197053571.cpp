//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

int N;
vector<LL> A;

LL ans = 0;
vector<pair<LL,LL>> manip;

void solve(){
	sort(A.begin(),A.end());
	vector<LL> neg,pos;
	for(int i=0;i<N;i++){
		if(A[i]<0) neg.push_back(A[i]);
		else pos.push_back(A[i]);
	}

	if(neg.size()==0){
		LL sum = pos[0];
		for(int i=1;i<pos.size()-1;i++){
			manip.push_back(pair<LL,LL>(sum,pos[i]));
			sum -= pos[i];
		}
		manip.push_back(pair<LL,LL>(pos[pos.size()-1],sum));
		ans = pos[pos.size()-1]-sum;
		return;
	}
	if(pos.size()==0){
		LL sum = neg[neg.size()-1];
		for(int i=neg.size()-2;i>=0;i--){
			manip.push_back(pair<LL,LL>(sum,neg[i]));
			sum -= neg[i];
		}
		ans = sum;
		return;
	}

	LL sum = neg[0];
	for(int i=0;i<pos.size()-1;i++){
		manip.push_back(pair<LL,LL>(sum,pos[i]));
		sum -= pos[i];
	}
	manip.push_back(pair<LL,LL>(pos[pos.size()-1],sum));
	sum = pos[pos.size()-1] - sum;
	for(int i=neg.size()-1;i>=1;i--){
		manip.push_back(pair<LL,LL>(sum,neg[i]));
		sum -= neg[i];
	}
	ans = sum;
}
 
int main(){
    cin >> N;
    A = vector<LL>(N);
    for(int i=0;i<N;i++) cin >> A[i];
 
    solve();

	cout << ans << endl;
    for(int i=0;i<manip.size();i++) {
    	cout << manip[i].first << " " << manip[i].second << endl;
    }
    return 0;
}