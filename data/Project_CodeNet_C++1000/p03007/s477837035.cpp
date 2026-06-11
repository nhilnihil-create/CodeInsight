#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath> // sqrt
#define _GLIBCXX_DEBUG // check []
#define DIVISOR 1000000007

using namespace std;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<int64_t, int64_t> pII;

template<typename T>
void cins(vector<T>& arr) { for(T& e: arr) cin >> e; }

#ifdef DEBUG
#define debug(fmt, ...) \
    printf("[debug: %s] " fmt, __func__, __VA_ARGS__)
#define ps(arr) \
    debug("size %ld: ", arr.size()); \
    for(auto e: arr) cout << e << " "; \
    cout << endl;
#else
#define debug(fmt, ...)
#define ps(arr)
#endif


int main(void) {
    int num;
    cin >> num;
    vector<int> arr(num);
    cins(arr);
    sort(arr.begin(), arr.end());
    deque<int> deq;
    for(int i = 0; i < num; i++) {
        deq.push_back(arr[i]);
    }

    vector<pii> ans;
    while(deq.size() > 1) {
        int n1 = deq.front(); deq.pop_front();
        int n2 = deq.back(); deq.pop_back();
        int pos = n2-n1;
        int neg = n1-n2;
        // last time
        int flag = (!deq.empty() && deq.front() >= 0);
        debug("%d, %d <- %d\n", n1, n2, flag);
        // pos
        if(!flag) {
            ans.push_back(make_pair(n2, n1));
            deq.push_back(pos);
        // neg
        } else {
            ans.push_back(make_pair(n1, n2));
            deq.push_front(neg);
        }
    }

    cout << abs(deq.front()) << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}