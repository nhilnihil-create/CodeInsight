#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif 

using namespace std;

#define TRACE(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << endl;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]";
	err(++it, args...);
}

#define MAXN ((int)2e5+5)
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9 + 9)
#define ll long long
#define _ << " " <<
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define LOG(x) if(DEBUG) cerr << x << endl;
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define pii pair<int,int>
#define mid ((l+r)/2)
#define BASE 29
#define BASE2 41

int n;

struct Node
{
	bool is_end = 0;
	Node* ch[26] = {NULL};
};

Node* head = NULL;

void add(string s)
{
	auto cur = head;
	
	for (int i = 0; i < s.size(); ++i)
	{
		if(cur->ch[s[i]-'a'] == NULL)
			cur->ch[s[i]-'a'] = new Node;
		cur = cur->ch[s[i]-'a'];
	}

	cur->is_end = true;
}

int count(Node* node)
{
	int res = node->is_end;
	for (int i = 0; i < 26; ++i)
		if(node->ch[i])
			res += count(node->ch[i]);
	return res;
}

int hash2(string s)
{
	int res = 0;

	for (int i = 0; i < s.size(); ++i)
		res = (res * BASE + (s[i] - 'a') + 1) % MOD;
	return res;
}

int hash3(string s)
{
	int res = 0;

	for (int i = 0; i < s.size(); ++i)
		res = (res * BASE2 + (s[i] - 'a') + 1) % MOD;
	return res;
}


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	head = new Node;

	vector <pii> v;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string a;
		cin >> a;
		v.pb({hash2(a), hash3(a)});
		// add(a);
	}

	sort(all(v));

	int ct = 0;
	int t = 0;
	while(t < v.size())
	{
		while(v[t].first == v[t+1].first && v[t].second == v[t+1].second) t++;
		ct++;
		t++;
	}

	cout << ct << endl;

	// cout << count(head) << endl;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/