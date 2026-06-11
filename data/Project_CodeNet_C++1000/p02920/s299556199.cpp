#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    multiset<ll> s, status, tmp;
    //sは与えられる集合、statusはシミュレーションの状態、tmpはstatusのコピー先
    
    //入力部
    cin >> n;
    int j;
    for(int i = 0; i < (1 << n); i++){
        cin >> j;
        s.insert(j);
    }

    status.insert(*(s.rbegin()));
    s.erase(*(s.rbegin()));
    for(int i = 0; i < n; i++){
        tmp = status; //状態を保存しておき、tmpを変化させていく、statusは参照するだけ
        for(auto e : status){ //現在の状態の最小の値から見ていく
            auto itr = s.lower_bound(e); //現在見ている値の中で最も左にあるものを参照
            if(itr == s.begin()){ //その位置が最左端ならシミュレーション失敗
                cout << "No" << endl;
                return 0;
            }
            tmp.insert(*prev(itr)); //見ている値よりも小さい物を取る
            s.erase(prev(itr));
        }
        status = tmp; //状態を更新する
    }

    //シミュレーションに成功したらYes
    cout << "Yes" << endl;
    return 0;
}