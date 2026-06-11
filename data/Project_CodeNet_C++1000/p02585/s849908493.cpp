#include <bits/stdc++.h>
using namespace std;
#define chmax(x, y) { x = max(x, y); }

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N); //順列の配列
    vector<int> C(N); //各マスに書かれた点数の配列
    for(int i = 0; i < N; i++){
        cin >> P.at(i);
    }
    for(int i = 0; i < N; i++){
        cin >> C.at(i);
    }
    for(int i = 0; i < N; i++){
        P.at(i)--; //1からstartだとめんどいのでデクリメント
    }
    long long ans = -1e18; //負の無限大
    for(int si = 0; si < N; si++){
        int x = si; //siをいじると壊れるので、xにsiを入れておく
        vector<int> score; //開始位置を決めると回り方が決まる。その周り方で通る各マスのスコア
        long long sum = 0; //配列scoreの合計値
        while(true){
            x = P.at(x); //位置を回していく
            score.push_back(C.at(x));
            sum += C.at(x);
            if(x == si){ //開始地点に戻ってきたらbreak
                break;
            }
        }
        int l = score.size(); //その周り方で何マス通るのか
        long long t = 0;
        for(int i = 0; i < l; i++){
            t += score.at(i);
            if(i + 1 > K){ //1周期の中でKを超えたとき、このbreakがないと壊れる
                break;
            }
            long long now = t;
            if(sum > 0){
                long long e = (K - (i + 1)) / l; //sumが正のとき、後ろに行けば行くほど高得点が取れる
                now += sum * e;
            }
            chmax(ans, now);
        }
    }
    /*for(int i = 0; i < N; i++){
        int score = 0;
        int blank = i;
        for(int j = 0; j < K; j++){
            score += C.at(P.at(blank) - 1);
            blank = P.at(blank) - 1;
        }
        cout << score << endl;
        if(score_max < score){
            score_max = score;
        }
    }*/
    cout << ans << endl;
}