#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DEBUG - Start of snippet
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char& c){
	string res;
	return "'" + res + c + "'";
}
 
string to_string(bool b) {
	return (b ? "True" : "False");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
	if (!first) {
    	res += ", ";
  	}
  	first = false;
	res += to_string(v[i]);
	}
	res += "}";
	return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}
 
template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
   	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
   	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr<<endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "\t[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else		
#define debug(...) 0
#endif
// DEBUG - End of snippet

// THINK: INT vs LONG LONG?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	--x, --y;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; ++i) {
		adj[i].push_back(i + 1);
		adj[i + 1].push_back(i);
	}
	adj[x].push_back(y);
	adj[y].push_back(x);

	debug(adj);	

	vector<int> dist(n);
	auto bfs = [&](int s) {
		vector<bool> vis(n);
		queue<int> q;

		q.push(s);
		vis[s] = true;
		dist[s] = 0;

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int v: adj[u]) {
				if (vis[v]) continue;
				dist[v] = dist[u] + 1;
				vis[v] = true;
				q.push(v);
			}
		}
	};

	vector<int> cnt(n);
	for (int i = 0; i < n; ++i) {
		bfs(i);
		for (int j = i + 1; j < n; ++j) {
			cnt[dist[j]]++;
		}
		dist.assign(n, 0);
	}

	for (int i = 1; i < n; ++i) {
		cout << cnt[i] << '\n';
	}
	cout << '\n';


	return 0;
}