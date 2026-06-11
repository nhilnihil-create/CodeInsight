#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
/*子を持たない節点は外部節点(external node)または葉(leaf)と呼ばれる。葉でない節点は内部接点(internal node)と呼ぶ。
*/
const int MAX_N =100010;
int n;//頂点数
int parent[MAX_N];//親のノード番号
int child[MAX_N];//子供
int brother[MAX_N];

void rec(){
	for(int i =0;i < n;i++){
		cout << "node " << i << ": parent = " << parent[i] << ", depth = " << flush;
		int cnt = 0;
		for(int j =i;parent[j]!=-1;j =parent[j]) cnt++;
		cout << cnt << ", " << flush;

		if(parent[i]==-1)cout << "root, " << flush;
		else if(child[i]==-1)cout << "leaf, " << flush;
		else cout << "internal node, " << flush;

		cout << "[";
		for(int j =child[i];j !=-1;j =brother[j]){
			if(j!=child[i]){
				cout <<", ";
			}
			cout <<j;
		}
		cout <<"]"<<endl;;
	}
}

int main(){
	cin>>n;
	fill(parent,parent+MAX_N,-1);
	fill(child,child+MAX_N,-1);
	fill(brother,brother+MAX_N,-1);
	for(int i =0;i < n;i++){
		int node,k,prev;
		cin>>node>>k;
		for(int j =0;j < k;j++){
			int x;
			cin>>x;
			parent[x]=node;
			if(j==0)child[node] =x;
			else brother[prev] =x;
			prev = x;
		}
	}
	rec();
	return 0;
}