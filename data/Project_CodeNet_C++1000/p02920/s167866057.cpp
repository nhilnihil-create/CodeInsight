#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;


int k, n;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>k;
    n = 1<<k;
    multiset<int> todo;
    for (int i=0; i<n; i++) {
	cin>>a[i];
	todo.insert(a[i]);
    }

    vector<int> have;
    have.push_back(*todo.rbegin());
    todo.erase(--todo.end());


    for (int it=0; it<k; it++) {
	sort(have.begin(), have.end());
	vector<int> nhave;

	while (have.size()) {
	    int at = have.back();
	    have.pop_back();
	    if (*todo.begin() >= at) {
		out("No");
	    }
	    auto iter = std::prev(todo.lower_bound(at));
	    int take = *iter;
	    todo.erase(iter);
	    nhave.push_back(take);
	    nhave.push_back(at);
	}

	swap(have, nhave);
    }


    cout<<"Yes\n";    
    return 0;
}
