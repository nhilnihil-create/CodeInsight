#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int, int>> conditions(m);
    for (int i=0;i<m;i++){
        int si, ci;
        cin >> si >> ci;
        conditions[i] = make_pair(si, ci);
    }
    vector<int> memo(n+1);
    for (int i=1;i<=n;i++){
        memo[i] = -1;
    }
    for (auto cond : conditions){
        if (cond.first > n  || (memo[cond.first] != -1 && memo[cond.first] != cond.second)){
            cout << "-1" << endl;
            return 0;
        } else {
            memo[cond.first] = cond.second;
        }
    }
    if (n == 1 && (memo[1] == 0 || memo[1] == -1)){
        cout << 0 << endl;
        return 0;
    }
    for (int i=1;i<n+1;i++){
        if (i==1 && memo[i] == 0){
            cout << "-1" << endl;
            return 0;
        }
        if (memo[i] == -1){
            if (i == 1){
                cout << 1;
            } else {
            cout << 0;
            }
        } else {
            cout << memo[i];
        }
    }
    cout << endl;
    return 0;
}