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
    for(int i = 1; i < K; i++){
        auto ite = lower_bound(can.begin(), can.end(), L[i - 1] + C + 1);
        if(ite == can.end()) L[i] = can[size - 1];
        else{
            int ind2 = ite - can.begin();
            L[i] = can[ind2];
        }
    }
    R[K - 1] = can[size - 1];
    for(int i = K - 2; i >= 0; i--){
        auto ite = upper_bound(can.begin(), can.end(), R[i + 1] - C - 1);
        if(ite == can.begin()) R[i] = can[0];
        else{
            int ind2 = ite - can.begin() - 1;
            R[i] = can[ind2];
        }
    }
    for(int i = 0; i < K; i++){
        if(L[i] == R[i]){
            cout << L[i] << endl;
        }
    }
}