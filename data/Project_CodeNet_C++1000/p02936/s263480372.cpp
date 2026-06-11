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


using Graph = vector<vector<int>>;


Graph G(1000010);
vector<int> val(1000010);

void dfs(int nord, int p = -1) {
//    cout << nord << endl;
    for(auto itr : G[nord]) {
	if(itr == p) continue;
	val[itr] += val[nord];
	dfs(itr,nord); 
    }
}


int main(){
    int N,Q;
    cin >> N >> Q;
    G.resize(N);
    val.resize(N);
    rep(i,N-1) {
	int a,b;
	cin >> a >> b;
	a--;b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }
    rep(i,Q) {
	int p,x;
	cin >> p >> x;
	p--;
	val[p] += x;
    }



    dfs(0);

    rep(i,N) {
	cout << val[i] << " ";
    }
    cout << endl;
    
    return 0;
}

