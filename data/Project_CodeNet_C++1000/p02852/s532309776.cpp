#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> ans;
    int n_ans = 0;
    int cur = N;
    int step;
    while(cur != 0){
        step = min(M, cur);
        while(S[cur - step] == '1'){
            step--;
            if(step == 0){
                cout << -1 << endl;
                return 0;
            }
        }
        ans.emplace_back(step);
        cur -= step;
    }
    int l = ans.size();
    for (int i=l-1; i>=0; i--){
        cout << ans[i];
        if(i != 0) cout << " " ;
    } cout << endl;
    return 0;
}