#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main (void){
    ll N;
    unsigned long long K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
        A[i]--;
    }

    deque<int> a;                   //履歴のメモ，2重終端que
    vector<bool> Tripped(N,false);  //その町は既に訪れているか
    int tmp=0;  //0-index
    while(true){
        // 一度訪れた町にたどり着いた場合
        if(Tripped[tmp]){
            while(a[0] != tmp){
                // 閉路にたどり着くまでの数手を除く
                --K;
                a.pop_front();//キューの前から経路を抜いていく
                if(K == 0){
                    cout << a[0] + 1 << endl;
                    return 0;
                }
            }
            break;
        }
        //履歴を保存
        a.push_back(tmp);
        Tripped[tmp] = true;
        tmp=A[tmp]; //次の町
    }
    // a.size():閉路の大きさ
    cout << a[K % a.size()] + 1 << endl;
    return 0;
}