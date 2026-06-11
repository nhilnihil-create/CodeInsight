// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare_by_b(pair<int, int>a, pair<int, int>b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}

int main()
{
    int n;

    cin >> n;

    pair<int, int>p;

    vector<pair<int, int>>v;

    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;

        v.push_back(p);
    }

    sort(v.begin(), v.end(), compare_by_b);

    long long time = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        time += v[i].first;
        if (time > v[i].second) {
            ok = false;
            break;
        }
    }

    if (ok) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;



}

