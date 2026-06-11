#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    int A[N][N-1];
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            int a;
            cin >> a;
            A[i][j] = a - 1;
        }
    }

    int next[N];
    fill(next, next+N, 0);
    bool battled[N];

    int cnt = 0;
    int ans = 0;
    while(cnt != N){
        cnt = 0;
        ans++;
        fill(battled, battled+N, false);

        //cout << "### Day " <<  ans << " ###" << endl;
        for(int i=0; i<N; i++){
            //cout << "--- " <<  i << " ---" << endl;
            
            //その日は戦い済み
            if(battled[i]) continue;

            //全日程を終了している
            if(next[i] == N-1){
                cnt++;
                continue;
            }

            int enemy = A[i][next[i]];

            //cout << i << " " << A[i][next[i]] << " " << enemy  << " " << A[enemy][next[enemy]] << endl;

            //相手の次の対戦者が自分かつまだ対戦可能なら
            if(A[enemy][next[enemy]] == i && !battled[enemy] && next[enemy] != N-1){
                next[i]++;
                next[enemy]++;
                battled[i] = true;
                battled[enemy] = true;
            }
            if(!battled[i]) cnt++;
        }
    }

    ans--;

    bool b = false;
    for(int i=0; i<N; i++){
        if(next[i] != N-1) b = true;
    }
    if(b) ans = -1;
    cout << ans;

    return 0;
}