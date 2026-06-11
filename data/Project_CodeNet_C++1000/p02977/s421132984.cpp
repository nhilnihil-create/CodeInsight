#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <utility>
#define ll long long
#define ld long double
using namespace std;

int main() {
	int N;
	cin >> N;
	bool flag=1;
	int k=N;
	while(k>1){
	    if(k%2==1) flag=0;
	    k /= 2;
	}
	if(flag){
	    cout << "No" << endl;
	    return 0;
	}
	cout << "Yes" << endl;
	vector<vector<int>> ans(1+N*2);
	int p=1;
	while(p<N+3){
	    int q=(p==3 ? N+1 : p+1);
	    ans[p].push_back(q);
	    ans[q].push_back(p);
	    p=q;
	}
	for(int i=4; i+1<=N; i+=2){
	    ans[i].push_back(i+1);
	    ans[i+1].push_back(i);
	    ans[i].push_back(1);
	    ans[1].push_back(i);
	    ans[1].push_back(N+i+1);
	    ans[N+i+1].push_back(1);
	    ans[N+i].push_back(N+i+1);
	    ans[N+i+1].push_back(N+i);
	}
	if(N%2==0){
	    int s=N^(N-2);
	    ans[N].push_back(s);
	    ans[s].push_back(N);
	    ans[2*N-1].push_back(2*N);
	    ans[2*N].push_back(2*N-1);
	}
	for(int i=1; i<=N*2; ++i){
	    for(int j=0; j<ans[i].size(); ++j){
	        if(i<ans[i][j]){
	            cout << i << ' ' << ans[i][j] << endl;
	        }
	    }
	}
	return 0;
}
