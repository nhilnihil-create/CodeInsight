#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

int main() {
    int N;
    scanf("%d", &N);
    int num = (int)pow(2, N);
    multiset<int> line, que;
    for (int i = 0; i < num; i++) {
        int tmp;
        scanf("%d", &tmp);
        que.insert(tmp);
    }
    line.insert(*que.rbegin());
    que.erase(prev(que.end()));
    for (int i = 0; i < N; i++) {
        auto cur_it = line.rbegin();
        vector<int> nline;
        while (cur_it != line.rend()) {
              auto tmp_it = que.lower_bound(*cur_it);
              if (tmp_it == que.begin()) break;
              cur_it++;
              tmp_it = prev(tmp_it);
              nline.push_back(*tmp_it);
              que.erase(tmp_it);
        }
        if ((int)line.size() != (int)nline.size()) {
           return !printf("No\n");
        }
        for (int i = 0; i < (int)nline.size(); i++) {
            line.insert(nline[i]);
        }
    }
    puts("Yes");

    return 0;
}
