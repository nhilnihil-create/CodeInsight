#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int N, M;
    cin>>N>>M;
    string S;
    cin>>S;
    reverse(S.begin(), S.end());
    int now = 0;
    bool can = true;
    bool tmpcan;
    vector<int> ans;
    while(now < S.size()-1){
        tmpcan = false;
        for(int step=M;step>0;--step){
            if(S[now+step]=='0'){
                now += step;
                ans.push_back(step);
                tmpcan = true;
                break;
            }
        }
        if(!tmpcan) {
            can = false;
            break;
        }
    }
    if(can){
        reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.size();++i){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
}
