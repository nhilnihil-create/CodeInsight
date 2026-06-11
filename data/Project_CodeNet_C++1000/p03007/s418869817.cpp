#include<algorithm>
#include<cstdio>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int, int> P;

const int MAX_N = 1e5;
int n;
vector<int> a;
vector<P> ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int b;
        scanf("%d", &b);
        a.emplace_back(b);
    }
    sort(a.begin(), a.end());

    vector<int>::iterator c = upper_bound(a.begin(), a.end(), 0);
    if (c == a.begin()) c++;
    if (c == a.end()) c--;
    vector<int>::iterator b = prev(c);
    ans.emplace_back(*c, *b);
    int d = *c - *b;
    a.erase(c); 
    a.erase(b); 
    while (!a.empty()) {
        if (a.back() > 0) {
            int e = ans.back().first;
            ans.back().first= ans.back().second;
            ans.back().second = e;
            d = -d;
        }
        if (a.back() >= d) {
            ans.emplace_back(a.back(), d);
            d = a.back() - d;
        }
        else {
            ans.emplace_back(d, a.back());
            d = d - a.back();
        }
        a.pop_back();
    }

    printf("%d\n", d);
    for (int i = 0; i < n - 1; i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
