#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int N_MAX = 1005;
int A[N_MAX][N_MAX];
int now[N_MAX];
bool todayend[N_MAX];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n-1; j++)cin >> A[i][j];
    }

    bool done = true;
    bool allfinished;
    int day = 0;
    memset(now, 0, sizeof(now));
    while(done){
        day++;
        allfinished = true;
        done = false;
        memset(todayend, false, sizeof(todayend));

        for(int i = 1; i <= n; i++){
            if (now[i] == n-1)continue;
            allfinished = false;

            if (A[i][now[i]] < i && !todayend[i]){
                int target = A[i][now[i]];
                if (A[target][now[target]] == i && !todayend[target]){
                    now[i]++;
                    now[target]++;
                    todayend[i] = true;
                    todayend[target] = true;
                    done = true;
                }
            }
        }
    }
    if (allfinished)cout << day-1 << endl;
    else cout << -1 << endl;
    return 0;
}