#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

priority_queue<P> que[20];

int main()
{
    int n;
    cin >> n;
    int p[20];
    p[0] = 1;
    int s[300000];
    P pa[300000];
    bool maked[300000];
    fill(maked, maked + p[n], false);
    for(int i = 1; i < 20; i++) p[i] = p[i - 1] * 2;
    for(int i = 0; i < p[n]; i++){
        cin >> s[i];
        pa[i] = P(s[i], i);
    }
    sort(pa, pa + p[n], greater<P>());
    que[0].push(pa[0]);
    maked[0] = true;
    for(int i = 1; i <= n; i++){
        int j = 0;
        while(que[i - 1].size()){
            P nowp = que[i - 1].top();
            que[i - 1].pop();
            for(; j < p[n]; j++){
                if(!maked[j] && pa[j].first < nowp.first){
                    que[i].push(nowp);
                    que[i].push(pa[j]);
                    maked[j] = true;
                    break;
                }
            }
            if(j == p[n]) break;
        }
        if((int)que[i].size() != p[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}