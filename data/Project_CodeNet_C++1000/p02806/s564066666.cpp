#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int N;
    int ans=0;
    cin >> N;
    vector<string> s;
    vector<int> t;
    string title_tmp;
    int time_tmp;
    bool sleep_flag;

    rep(i,N){
        cin >> title_tmp >> time_tmp;
        s.push_back(title_tmp);
        t.push_back(time_tmp);
    }
    string X;
    cin >> X;
    int target_idx;

    rep(i,N){
        if(X ==  s.at(i)){
            target_idx = i;
            break;
        }
    }

    target_idx++;

    for(int i = target_idx;i<N;i++){
        ans += t[i];
    }

    cout<<ans<<endl;
}