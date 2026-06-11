#include <iostream>
#include <fstream>
#include <algorithm>       // for next_permutation
#include <vector>
#include <queue>
#include <bits/stl_numeric.h>

#define DEBUG 0
#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

typedef vector<vector <int>> Graph;




ll solve() {
    int N;
    cin >> N;
    deque <int> a[1010];
    //各選手の現在の日程がいつまで埋まっているか
    vector<int> step(1010, 0);
    int M;//試合回数
    REP(i,N)
    {
        REP(j,N-1)
        {
            int x;
            cin >> x;
            //選手の試合相手を順番につっこむ
            a[i].push_back(x-1);
        }
    }
    //
    M = N*(N-1)/2;

    queue<int> que;
    //全選手つっこむ
    REP(i,N)que.push(i);

    int num = 0;
    while(que.size())
    {
        int ok=0;
        queue <int> que2;
        while(que.size())
        {
            int i = que.front();
            que.pop();
            //以下の条件を定めてi == 0から貪欲で行う
            //日程が超えていないか 選手が全日程試合を終えていないか
            //相手選手の直近で予定している試合相手がiか
            //相手選手の日程が超えていないか
            if(step[i] <= num && a[i].size() && a[a[i].front()].front() == i && \
            step[a[i].front()]<=num)
            {
                //スケジュールを更新
                step[i] = step[a[i].front()] = num + 1;
                //que2->次の周期の試合日程を組む順 最後にqueとswapする
                que2.push(i);
                que2.push(a[i].front());
                //試合日程の更新が成立したので取り出す
                a[a[i].front()].pop_front();
                a[i].pop_front();
               --M;
            }
        }
        ++num;
        if(M == 0)break;
        swap(que,que2);
    }

    int res;

    if(M)
    {
        res = -1;
    }
    else
    {
        res = num;
    }
    return res;
}

int main()
{
    cout << solve() << endl;
}
