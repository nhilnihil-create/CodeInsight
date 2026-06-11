#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<setw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値
#include <functional>//sort第三引数greater<型名>()で降順
#include <map>

using namespace std;
using ll = long long int;

int main(){
    int H,W;cin>>H>>W;
    vector<string> S(H);
    for(int i=0;i<H;i++) cin >> S[i];
    int cnt = 0;


    vector<vector<int>> H_cnt(H,vector<int>(W));
    vector<vector<int>> W_cnt(H,vector<int>(W));
    queue<int> que;

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='#'){
                while(que.size()){
                    int p = que.front();que.pop();
                    H_cnt[i][p] = cnt;
                }
                cnt = 0;
            }else{
                que.push(j);
                cnt++;
            }
        }
        while(que.size()){
            int p = que.front();que.pop();
            H_cnt[i][p] = cnt;
        }
        cnt = 0;
    }

    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            if(S[j][i]=='#'){
                while(que.size()){
                    int p = que.front();que.pop();
                    W_cnt[p][i] = cnt;
                }
                cnt = 0;
            }else{
                que.push(j);
                cnt++;
            }
        }
        while(que.size()){
            int p = que.front();que.pop();
            W_cnt[p][i] = cnt;
        }
        cnt = 0;
    }

    
    int ans = 0;
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) if(H_cnt[i][j]+W_cnt[i][j]>ans) ans = H_cnt[i][j] + W_cnt[i][j];
    cout << ans - 1 << endl;
    return 0;
}