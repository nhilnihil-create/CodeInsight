#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define reps(i, S, E) for (ll i = (S); i <= (E); i++)
#define rep(i, N) reps(i, 0, N-1)
int main(){
    int n;
    cin >> n;
    vector<int> adj[n+1];
    ll result = 0;

    // Connected components = Total no of vertices - Total no of edges
    
    // Total no of vertices
    for(ll i=1; i<=n; i++)
	result += i * (i+1)/2;

    // Total no of edges
    for(ll i=1; i<n; i++){
	ll  a, b;
	cin >> a >> b;
	if(a > b)
	    swap(a, b);
	ll edges = a * (n - b + 1);
	result -= edges;
    }
    cout << result << "\n";
    return 0;
}
