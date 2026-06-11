#include <bits/stdc++.h>
using namespace std;
#define REP(i, init, n) for(int i = (int)(init); i < (int)(n); i++)

#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define pint pair<int, int>
#define plong pair<long, long>

int N, M;
string S;

int main() {
    cin>>N>>M>>S;
    int count = 0, pos = N;
    vi ans = {};
    while(pos > 0){
        int i = M;
        if(pos-i < 0){
            i = pos;
            pos = 0;
            ans.push_back(i);        
            count++;
            break;
        }else{
            while(S[pos - i] !='0'){
                i--;
                if(i==0){
                    cout << -1 << endl;
                    return 0;
                }
            }
            pos -= i;
            ans.push_back(i);
            count++;
        }
    }
    reverse(ans.begin(), ans.end());
    //cout << count << endl;
    REP(i, 0, count){
        cout << ans[i] << " ";
    }
    cout << endl;
}