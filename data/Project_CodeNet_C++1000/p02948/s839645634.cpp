// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;


struct SegmentTree{
    int n;
    vector<int> value; //0始まりのインデックス
    int SIJK;

    SegmentTree(int N){
        SIJK = INF; // compareの内容に応じて変える
        n = 1;
        while(n < N) n *= 2;
        value.assign(2 * n - 1, SIJK);
        rep(i, N) value[i + n - 1] = i;
        for(int i = n - 2; i >= 0; i--){
            value[i] = compare(value[2 * i + 1], value[2 * i + 2]);
        }
    }

    int compare(int a, int b){
        return min(a, b); //問題に応じて変える
    }

    void update(int i, int x){
        i += n - 1;
        value[i] = x;
        while(i > 0){
            i = (i - 1)/2; // 親のノード
            value[i] = min(value[2 * i + 1], value[2 * i + 2]);
        }
    }

    int find(int a, int b, int k = 0, int l = 0, int r = -1){
        // [a, b) の区間に対するクエリについて
        // ノード k （区間 [l, r) 担当）が答える
        if(r < 0) r = n;
        if(r <= a || b <= l) return SIJK;
        if(a <= l && r <= b) return value[k];
        else{
            int m = (l + r) / 2;
            int tmp1 = find(a, b, 2 * k + 1, l, m);
            int tmp2 = find(a, b, 2 * k + 2, m, r);
            return compare(tmp1, tmp2);
        }
    }


};


int main(){
    int N, M;
    cin >> N >> M;
    SegmentTree sg(M);
    priority_queue<P> que;
    rep(i, N){
        P tmp;
        cin >> tmp.second >> tmp.first;
        que.push(tmp);
    }

    int sum = 0;
    while(!que.empty()){
        P tmp = que.top();
        que.pop();
        int a = tmp.second - 1, b = tmp.first;
        int f = sg.find(a, M);

        if(f == INF) continue;
        else{
            sg.update(f, INF);
            sum += b;
        }
    }

    cout << sum << endl;

}