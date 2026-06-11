#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M;
    while(cin >> N >> M && N>0 && M>0){
        vector<int> h(N);
        vector<int> w(M);
        for(int i = 0; i < N; i++){
            cin >> h[i];
        }
        for(int i = 0; i < M; i++){
            cin >> w[i];
        }
        vector<int> h_len(1500010, 0);
        for(int i = 0; i < N; i++){
            int tmp = 0;
            for (int j = 0; j < N - i; j++){
                tmp += h[i + j];
                h_len[tmp]++;
            }
        }
        vector<int> w_len(1500010, 0);
        for(int i = 0; i < M; i++){
            int tmp = 0;
            for (int j = 0; j < M - i; j++){
                tmp += w[i + j];
                w_len[tmp]++;
            }
        }
        int count = 0;
        for(int i = 1; i < 1500010; ++i){
            if(h_len[i] != 0){
                if(w_len[i] != 0){
                    count += (h_len[i] * w_len[i]);
                }
            }
        }
        cout << count << endl;
    }
}