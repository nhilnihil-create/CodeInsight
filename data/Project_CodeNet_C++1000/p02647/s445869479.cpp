#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int>powers(N);

    for (int i=0; i<N; i++)cin >> powers[i];
    vector<int> last_powers(N);
    for (int i=0; i<K; i++){
        vector<int>table(N*2);
        vector<int>total(N*2);
        for (int j=0; j<N; j++){
            int dj = powers[j];
            table[max((j-dj)*2-1,0)]++;
            table[min((j+dj)*2+1,N*2-1)]--;
        }
        for (int j=0; j<N*2; j++){
            if(j>0) table[j] += table[j-1];
        }
        for (int j=0; j<N; j++)powers[j] = table[j*2];
        
        bool exit_condition = true;
        for (int j=0; j<N; j++){
            if (table[j] != N){
                exit_condition = false;
                break;
            }
        }
        if (exit_condition){
            for (int j=0; j<N;j++)cout << powers[j] << " ";
            cout << endl;
            exit(0);
        }    
    
    }

    for (int k=0; k<N; k++)cout << powers[k] << " ";
    cout << endl;
    exit(0);    
}