#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(void) {
    int H, W;
    cin >> H >> W;
    vector<string> s(H);

    for (int i = 0; i < H; i++)
    {
        cin >> s[i];
    }
    
    deque<pii> deq;
    vector<vector<int>> cost(H, vector<int>(W, INF));

    if(s[0][0] == '.'){
        cost[0][0] = 0;
    } else {
        cost[0][0] = 1;
    }

    vector<int> dh = {0,1};
    vector<int> dw = {1,0};

    deq.push_back(pii(0,0));

    while (!deq.empty())
    {
        pii front = deq.front();
        deq.pop_front();

        for (int i = 0; i < 2; i++)
        {
            int h_next = front.first + dh[i];
            int w_next = front.second + dw[i];

            if(h_next >= H) continue;
            if(w_next >= W) continue;

            if(s[h_next][w_next] == '#' && s[front.first][front.second] == '.'){
                if(cost[h_next][w_next] > cost[front.first][front.second] + 1){
                    cost[h_next][w_next] = cost[front.first][front.second] + 1;
                    deq.push_back(pii(h_next, w_next));
                }
            } else {
                if(cost[h_next][w_next] > cost[front.first][front.second]){
                    cost[h_next][w_next] = cost[front.first][front.second];
                    deq.push_front(pii(h_next, w_next));
                }
            }
            
        }
    }

    cout << cost[H-1][W-1] << endl;
    
    return 0;
}
