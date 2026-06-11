#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int N, M;
int S[1<<18];
bool used[1<<18];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N;
    M = 1<<N;
    for(int i = 0; i < M; i++) cin >> S[i];
    sort(S, S+M, greater<int>());
    used[0] = true;
    vector<int> v;
    v.push_back(S[0]);
    for(int i = 0; i < N; i++){
        int m  = 1<<i;
        int cnt = 0;
        int sz = v.size();
        for(int j = 0; j < M; j++){
            if(!used[j] && v[cnt] > S[j]){
                cnt++;
                used[j] = true;
                v.push_back(S[j]);
                if(cnt == sz) break;
            }
        }
        if(cnt < sz){
            cout << "No" << endl;
            return 0;
        }
        sort(v.begin(), v.end(), greater<int>());
    }
    cout << "Yes" << endl;
}