#include <iostream>
#include <vector>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> ans(n);
    FOR (i, 0, n) {
        scanf("%d\n", &A[i]);
    }
    int cur_max = 0;
    int cur_max_next = 0;
    for (int a : A) {
        if (a>=cur_max) {
            cur_max_next = cur_max;
            cur_max = a;
        } else if (a>cur_max_next) {
            cur_max_next = a;
        }
    }
    FOR (i, 0, n) {
        if (A[i]==cur_max) {
            ans[i] = cur_max_next;
        }else{
            ans[i] = cur_max;
        }
        printf("%d\n", ans[i]);
    }
    return 0;
}