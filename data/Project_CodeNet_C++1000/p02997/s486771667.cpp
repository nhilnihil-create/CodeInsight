#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N,K;
    cin >> N >> K;
    if(K > N * (N - 1) / 2 - (N - 1)) {
        cout << -1 << endl;
    }
    else {
        vector<P> ret;
        for(int i = 0;i < N - 1;i++) {
            for(int j = i + 1;j < N;j++) {
                ret.push_back(P(i,j));
            }
        }
        cout << N * (N - 1) / 2 - K << endl;
        vector<bool> ret2(N * (N - 1) / 2,true);
        int cnt = 0;
        int cnt3 = 0;
        for(int i = 0;i < N;i++) {
            bool cnt2 = true;
            for(int j = 0;j < N - 1 - (i + 1);j++) {
                if(cnt3 == K) {
                    cnt2 = false;
                    break;
                }
                ret2.at(cnt) = false;
                cnt++;
                cnt3++;
            }
            cnt++;
            if(cnt2 == false) {
                break;
            }
        }
        for(int i = 0;i < N * (N - 1) / 2;i++) {
            if(ret2.at(i) == true) {
                cout << ret.at(i).first + 1 << " " << ret.at(i).second + 1 << endl;
            }
        }
    }
}