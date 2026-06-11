#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 200005;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    scanf("%d", &n);
    multiset <pair <int, int> > st;
    bool no = false;
    for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (y - x < 0) {
			no = true;
		}
		st.insert({y, y - x});
	}
	if (no) {
		printf("No");
	} else {
		int lst = 0;
		auto it = st.begin();
		while (it != st.end()) {
			int l = it->se, r = it->fi;
			if (l >= lst) {
				lst += r - l;
			} else {
				return printf("No"), 0;
			}
			it++;
		}
		printf("Yes");
	}
    return 0;
}
