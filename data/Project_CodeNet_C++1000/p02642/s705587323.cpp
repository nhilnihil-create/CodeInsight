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
const int N = 2e6+321, E=14e5;

ll xx[8]={1, 1, -1, -1, 1, -1, 0, 0};
ll yy[8]={1, -1, 1, -1, 0, 0, 1, -1};

int a[N], b[N], used[N], ans;

vector <int> v[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(!used[a[i]]){
			used[a[i]]=1;
			for(int j=2; j*a[i]<=N/2; j++)
				b[j*a[i]]=1;
		}
		else
			b[a[i]]=1;
	}
	for(int i=0; i<n; i++)
		if(!b[a[i]])
			ans++;
	cout << ans;
    return 0;
}
