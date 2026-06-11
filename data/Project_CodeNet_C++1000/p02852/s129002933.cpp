#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    int N,M; cin>>N>>M;
    string S; cin>>S;
    vi ans;
    int pos=N;
    while(1){
        int move=M;
        bool over=true;
        for (int i = 0; i < M; i++){
            if(pos-move<=0){
                ans.push_back(pos);
                for (int j = 0; j < ans.size(); j++){
                    cout<<ans[ans.size()-1-j]<<" ";
                }
                cout<<endl;
                return 0;
            }
            if((int)S[pos-move]-(int)'0')move--;
            else{
                ans.push_back(move);
                over=false;
                break;
            }
        }
        if(over){
            cout<<-1<<endl;
            return 0;
        }
        pos-=move;
    }
}
