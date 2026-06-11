// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<P> work(N);
    rep(i, N){
        P tmp;
        cin >> tmp.second >> tmp.first;
        work[i] = tmp;
    }
    sort(all(work));

    int time = 0;
    bool flag = true;
    rep(i, N){
        time += work[i].second;
        if(time > work[i].first){
            flag = false;
            break;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;


}