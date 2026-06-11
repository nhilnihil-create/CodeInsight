#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef pair<int, int> pp;

static const int MAX = 1000;
deque<int> ary[MAX];
deque<pp> que;

void check(int u){
    if(ary[u].size() == 0) return;
    int v = ary[u].front();
    if(ary[v].front() == u){
        que.push_back(u < v ? pp(u, v) : pp(v, u));
    }
}

int main(){
    int n, op;
    cin >> n;
    rep(i, n) rep(j, n-1){
        scanf("%d", &op);
        op--;
        ary[i].push_back(op);
    }
    rep(i, n){
        check(i);
    }
    int day = 0;
    while(!que.empty()){
        day++;
        sort(que.begin(), que.end());
        que.erase(unique(que.begin(), que.end()), que.end());
        deque<pp> prevQ;
        swap(que, prevQ);
        for(pp x : prevQ){
            int i = x.first, j = x.second;
            ary[i].pop_front();
            ary[j].pop_front();
            check(i);
            check(j);
        }
    }
    rep(i, n){
        if(!ary[i].empty()){
            day = -1;
            break;
        }
    }
    cout << day << "\n";
}
            