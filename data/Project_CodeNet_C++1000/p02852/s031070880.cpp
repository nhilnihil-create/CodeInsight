#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    //ゴールから始めて,なるべく長い距離を使って移動を繰り返す.
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> ids;
    for(int i = 0;i < n+1;i++){
        if(s[i] == '0'){
            ids.push_back(i);
        }
    }

    vector<int> ans;

    int now = n;
    while(now != 0){
        auto itr = lower_bound(ids.begin(),ids.end(), now - m);
        int next = *itr;
        ans.push_back(now - next);
        if(now == next){
            cout << -1 << endl;
            return 0;
        }
        now = next;
    }

    for(int i = ans.size() - 1;i >= 0;i--){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
