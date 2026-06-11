#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


const int N = (1 << 18);

int S[N];
bool made[N];

int main(){

    vector<int> v;
    int N;

    cin >> N;

    int m = (1 << N);

    for(int i = 0; i < m; i++)
        cin >> S[i];

    sort(S, S + m);
    v.push_back(S[m - 1]);
    made[m - 1] = true;
    for(int i = 0; i < N; i++){
        int cur = 0;
        int s = v.size();

        for(int j = m - 1; j >= 0; j--){
            if(!made[j]){
                if(v[cur] > S[j]){
                    v.push_back(S[j]);
                    made[j] = 1;
                    cur++;
                }
                if(cur == s) break;
            }
            if(j == 0){
                cout << "No\n";
                return 0;
            }
        }
        sort(v.begin(), v.end(), greater<int>());
    }
    cout << "Yes\n";
    return 0;
}
