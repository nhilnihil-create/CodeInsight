#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    if(N == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    for(int i = N - 1; i >= 1; i--){
        if(H[i] < H[i - 1]) H[i - 1]--;
    }
    for(int i = 0; i < N - 1; i++){
        if(H[i] > H[i + 1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}