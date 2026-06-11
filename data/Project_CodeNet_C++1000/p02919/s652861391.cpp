#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i=0;i<N;i++) cin >> P[i];
    for (int i=0;i<N;i++) P[i]--;
    vector<int> idx(N);
    for (int i=0;i<N;i++) idx[P[i]] = i;
    set<int> s;
    ll ans = 0;
    for (int x = N-1;x>=0;x--){
        // 大きい数から順に処理していく
        int i = idx[x];
        // cはある値が２番目に大きくなる区間の個数
        ll c = 0;
        //現在見ている数をsetに入れる
        s.insert(i);
        // lは現在見ている数より大きい左にある数の位置
        // rは現在見ている数より大きい右にある数の位置
        vector<int> l(2,-1);
        vector<int> r(2,N);
        auto it = s.find(i);
        for (int j=0;j<2;j++){
            if (it == s.begin()) break;
            it--;
            l[j] = *it;
        }
        it = s.find(i);
        for (int j=0;j<2;j++){
            it++;
            if (it == s.end()) break;
            r[j] = *it;
        }
        // lsは見ている数から左にある大きな数への区間数
        vector<int> ls(2);
        ls[0] = i - l[0]; ls[1] = l[0] - l[1];
        vector<int> rs(2);
        rs[0] = r[0] - i; rs[1] = r[1] -r[0];
        //自分より大きい数を１個だけ含む区間数
        c = (ll)ls[0]*rs[1] + (ll)ls[1]*rs[0];

        ans += c*(x+1);
    }
    cout << ans << endl;

    return 0;
}