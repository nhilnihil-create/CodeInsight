#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N, M;
    cin >> N >> M;
    vector< vector<int> > data(N);

    for (int i = 0; i < M; ++i){
        int A, B;
        cin >> A >> B;
        data[A - 1].push_back(B - 1);
        data[B - 1].push_back(A - 1);
    }

    int flag[N];
    for (int i = 0; i < N; ++i){
        flag[i] = 0;
    }

    int ans = 1;
    for (int i = 0; i < N; ++i){
        if (flag[i] == 1){
            //何もしない
        } else{

            flag[i] = 1;
            int count = 0;

            vector<int> que;
            que.push_back(i);

            while(que.size() != 0){
                count += 1;

                int u = que.back();
                que.pop_back();

                for (int j = 0; j < data[u].size(); ++j){
                    int v = data[u][j];
                    if (flag[v] == 1){
                        //何もしない
                    } else{
                        flag[v] = 1;
                        que.push_back(v);
                    }
                }  
            }
            ans = max(ans, count);
        }
    }
    cout << ans << endl;
}