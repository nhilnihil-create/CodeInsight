#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
vector<int> a, b, c, d;
vector<int> pattern;
int ans = 0;

int score()
{
    int res = 0;
    for(int i = 0; i < Q; i++){
        if((pattern[b[i] - 1] - pattern[a[i] - 1]) == c[i]){
            res+=d[i];
        }
    }
    //cout << res;
    return res;
}

void changePattern(int index, int start)
{
    if(index == pattern.size()){
        // for(int i = 0; i < pattern.size(); i++){
        //     cout << pattern[i] << " ";
        // }
        ans = max(ans, score());
        // cout << endl;
        return;
    }
    for(int i = start; i <= M; i++){
        pattern[index] = i;
        changePattern(index+1, i);
    }
}

int main(void)
{
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    pattern.resize(N);
    for(int i = 0; i < Q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    changePattern(0, 1);
    cout << ans << endl;
    return 0;
} 