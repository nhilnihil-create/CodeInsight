#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

double dis(pair<int,int> t1, pair<int,int> t2) {
    int x1 = t1.first;
    int x2 = t2.first;
    int y1 = t1.second;
    int y2 = t2.second;
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

int f(int n) {
    int a = 1;
    while (n > 0) {
        a *= n;
        n--;
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int,int>> town(n);
    vector<int> a(n);
    rep(i, n) {
        scanf("%d %d", &town[i].first, &town[i].second);
        a[i] = i;
    }
    double sum = 0;
    do {
        rep(i, n) {
            if (i != 0) {
                pair<int,int> t1, t2;
                t1 = town[a[i-1]];
                t2 = town[a[i]];
                sum += dis(t1, t2);
            }
        }
    } while (next_permutation(a.begin(), a.end()));
    double ans = sum / f(n);
    printf("%.10lf\n", ans);
}