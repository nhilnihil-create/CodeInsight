#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    string S;
    cin >> S;

    int now = N;
    vector<int> ans;
    bool pos = true;
    while(now != 0){
        bool fl = false;
        for(int i=M; i>0; i--){
            int next = now - i;
            if(next < 0) continue;
            if(S[next] == '1') continue;
            fl = true;
            ans.push_back(i);
            now = next;
            break;
        }
        if(!fl){
            pos = false;
            break;
        }
    }

    if(!pos){
        cout << -1 << endl;
    }else{
        for(int i=ans.size()-1; i>=0; i--){
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}