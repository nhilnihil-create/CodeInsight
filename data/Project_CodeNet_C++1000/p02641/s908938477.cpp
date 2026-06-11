#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
  
#define mp make_pair
#define f first
#define s second
#define ll long long
#define pb push_back
#define popb pop_back
#define popf pop_front

using namespace std;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 2e9+7, mod=1e9+7;
const int N = 1e6+321, E=14e5;

ll xx[8]={1, 1, -1, -1, 1, -1, 0, 0};
ll yy[8]={1, -1, 1, -1, 0, 0, 1, -1};

bool a[200];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int n, x;
	cin >> x >> n;
	for(int i=0; i<n; i++){
		int q;
		cin >> q;
		a[q]=1;
	}
	if(!a[x]){
		cout << x;
		return 0;
	}
	int k=1;
	while(1){
		if(!a[x-k]){
			cout << x-k;
			return 0;
		}
	
		if(!a[x+k]){
			cout << x+k;
			return 0;
		}
		k++;
	}
    return 0;
}