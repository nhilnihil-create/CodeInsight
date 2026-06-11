#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

void merge(vector<pair<int,int>> left, vector<pair<int,int>> right, vector<pair<int,int>> &merged_a) {
    int i = 0, j = 0;
    while (i < left.size() || j < right.size()) {
        if ((i < left.size() && left[i].second <= right[j].second) || j == right.size()) {
            merged_a[i+j] = left[i];
            i++;
        } else {
            merged_a[i+j] = right[j];
            j++;
        }
    }
}

void merge_sort(vector<pair<int,int>> &a) {
    if (a.size() > 1) {
        int l_size = a.size() / 2;
        int r_size = a.size() - l_size;
        vector<pair<int,int>> left(l_size);
        vector<pair<int,int>> right(r_size);
        rep(i, l_size) {
            left[i] = a[i];
        }
        rep(i, r_size) {
            right[i] = a[l_size + i];
        }
        merge_sort(left);
        merge_sort(right);
        merge(left, right, a);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int,int>> a(n+1);
    rep(i, n+1) {
        if (i == 0) continue;
        a[i].first = i;
        scanf("%d", &a[i].second);
    }
    merge_sort(a);
    rep(i, n+1) {
        if (i == 0) continue;
        printf("%d", a[i].first);
        if (i != n) printf(" ");
        else printf("\n");
    }
}