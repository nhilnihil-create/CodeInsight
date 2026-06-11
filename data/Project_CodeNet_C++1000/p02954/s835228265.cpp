#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S; cin >> S;
    S += 'R';
    queue<int> q;
    int begin = 0;
    for(int i = 1; i < S.size(); ++i) {
        if(S[i] != S[i-1]){
            q.push(i - begin);
            begin = i;
        }
    }
    vector<int> ans(S.size());
    for(int i = 1; i < S.size()-1; ++i) {
        if(S[i] == 'L' && S[i-1] == 'R'){
            int x = q.front(); q.pop();
            ans[i] += x/2;
            ans[i-1] += (x+1)/2;
            x = q.front(); q.pop();
            ans[i] += (x+1)/2;
            ans[i-1] += x/2;
        }
    }
    for(int i = 0; i < S.size() - 1; ++i){
        cout << ans[i] << endl;
    }
    return 0;
}