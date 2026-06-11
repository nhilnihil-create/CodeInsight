#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<int> can;
    for(int i = 0; i < (int)S.size(); i++){
        if(S[i] == 'o') can.push_back(i + 1);
    }
    vector<int> L(K), R(K);
    int size = can.size();
    L[0] = can[0];
    int ind = 0;
    for(int i = 1; i < K; i++){
        while(can[ind] - L[i - 1] <= C) ind++;
        L[i] = can[ind];
    }
    R[K - 1] = can[size - 1];
    ind = size - 1;
    for(int i = K - 2; i >= 0; i--){
        while(R[i + 1] - can[ind] <= C) ind--;
        R[i] = can[ind];
    }
    for(int i = 0; i < K; i++){
        if(L[i] == R[i]){
            cout << L[i] << endl;
        }
    }
}