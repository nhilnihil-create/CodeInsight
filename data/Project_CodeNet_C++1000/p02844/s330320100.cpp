#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    string str;
    map<string, int> m;
    vector<string> vec;
    vector<string> vec2;

    cin >> num >> str;
    for (int i = 0; i < str.size() - 2; i++) {
        // 1桁目で同じ値が出たらスキップ
        // 0024だと2桁目の0ｽﾀｰﾄでは全く同じパターンを見ることになるので不要(024がかぶる)
        auto exists = find(vec.begin(), vec.end(), str.substr(i, 1)) != vec.end();
        if (exists == true) continue;

        vec.push_back(str.substr(i, 1));

        vec2.clear();  // 重複チェックは毎回初期化
        for (int j = i + 1; j < str.size() - 1; j++) {
            // 2桁目で同じ値が出たらスキップ
            // 0224だと3桁目の02以降は全く同じパターンを見ることになるので不要(024がかぶる)
            auto exists2 = find(vec2.begin(), vec2.end(), str.substr(j, 1)) != vec2.end();
            if (exists2 == true) continue;

            vec2.push_back(str.substr(j, 1));

            for (int k = j + 1; k < str.size(); k++) {
                string tmp;
                tmp = str.substr(i, 1) + str.substr(j, 1) + str.substr(k, 1);
                m[tmp]++;  // 組み合わせをmapに入れて重複回避
            }
        }
    }

    cout << m.size() << endl;
    //
}