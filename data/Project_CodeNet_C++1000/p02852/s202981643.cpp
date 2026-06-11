#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N,M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> vec;
    for(int i = 0;i < N + 1;i++) {
        if(S.at(i) == '0') {
            vec.push_back(N - i);
        }
    }
    reverse(vec.begin(),vec.end());
    int cnt = 0;
    bool ret = true;
    vector<int> ret2;
    for(int i = 0;i < N;i++) {
        auto itr = upper_bound(vec.begin(),vec.end(),cnt + M);
        int A = itr - vec.begin();
        if(vec.at(A - 1) == cnt) {
            ret = false;
            break;
        }
        else {
            ret2.push_back(vec.at(A - 1) - cnt);
            cnt = vec.at(A - 1);
        }
        if(cnt == N) {
            break;
        }
    }
    if(ret == false) {
        cout << -1 << endl;
    }
    else {
        reverse(ret2.begin(),ret2.end());
        for(int i = 0;i < ret2.size();i++) {
            cout << ret2.at(i) << " ";
        }
        cout << endl;
    }
}