#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main()
{
    int64_t N;
    cin >> N;
    vector<pair<int64_t, int64_t>>vec(N);
    for (int64_t i=0; i<N; i++) {
        int64_t n, m;
        cin >> n >> m;
        vec[i] = make_pair(n, m);
    }

    sort(vec.begin(), vec.end(), compare_by_b);
    int64_t sum_time = 0;
    bool work_ok = true;
    for (int64_t i=0; i<N; i++) {
        sum_time += vec[i].first;
        if (sum_time > vec[i].second) {
            work_ok = false;
            break;
        }
    }

    if (work_ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}