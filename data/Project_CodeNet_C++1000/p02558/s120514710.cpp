#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;

const int MAX = 2E5+5;
int link[MAX], sz[MAX];

int find(int a){
	if (link[a] == a)
		return a;
	else{
		link[a] = find(link[a]);
		return link[a];
	}
}

void unite(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a,b);
	sz[a] += sz[b];
	link[b] = a;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;

    cin >> n >> q;
    for (int i=0; i<n; ++i){
    	link[i] = i;
    	sz[i] = 1;
    }
    for (int i=0; i<q; ++i){
    	int t,u,v;
    	cin >> t >> u >> v;
    	if (t == 0){
    		unite(u,v);
    	}else{
    		u = find(u);
    		v = find(v);
    		cout << (u == v) << endl;
    	}
    }

    
	return 0;
}