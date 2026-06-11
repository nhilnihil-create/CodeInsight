#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    unsigned int result = 0,x;
    vector<unsigned int> A(N);
    for(int i = 0 ; i < N;i++){
        cin >> A[i];
        result ^= A[i];
    }
    for(auto i : A){
        cout << (result ^ i) << "\t";
    }
    return 0;
}
