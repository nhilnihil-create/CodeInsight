/**
 * Title: D - Face Produces Unhappiness
 * Url: https://atcoder.jp/contests/abc140/tasks/abc140_d
 * 
 * 方針：一番左の人の向きの人を最大化する
 */
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int N, K;
string S;

int main() {
    cin >> N >> K;
    cin >> S;

    vector<pair<char, int>> dic;

    char target;
    int cnt = 0;
    for(int i=0; i<N; i++) {
        if(i==0) {
            target = S[i];
            cnt++;
        } else {
            if(S[i]==target) {
                cnt++;
            } else {
                dic.push_back(make_pair(target, cnt));
                target = S[i];
                cnt = 1;
            }
        }
    }
    dic.push_back(make_pair(target, cnt));
    if(dic.size()==1) {
        cout << dic[0].second - 1 << endl;
        return 0;
    }

    // for(auto di:dic) {
    //     cout << "(" << di.first << "," << di.second << ")" << endl;
    // }

    int counter = 0;
    target = dic[0].first;
    // cout << target << endl;
    for(int i=0; i<dic.size(); i++) {
        if(i==0) continue;
        if(counter>=K) break;
        if(dic[i].first!=target) {
            dic[i].first = target;
            counter++;
        }
    }
    // for(auto di:dic) {
    //     cout << "(" << di.first << "," << di.second << ")" << endl;
    // }
    ll ans = 0;
    int tmp_ans = dic[0].second;
    for(int i=1; i<dic.size(); i++) {
        if(dic[i].first != dic[i-1].first) {
            ans += tmp_ans - 1;
            tmp_ans = dic[i].second;
            if(i==dic.size()-1) {
                ans += tmp_ans - 1;
            }
        } else {
            tmp_ans += dic[i].second;
            if(i==dic.size()-1) {
                ans += tmp_ans - 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}