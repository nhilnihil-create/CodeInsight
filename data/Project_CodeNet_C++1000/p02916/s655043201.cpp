#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N - 1);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N - 1; i++) cin >> C[i];
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += B[A[i] - 1];
        if(i > 0 && A[i - 1] + 1 == A[i]) sum += C[A[i - 1] - 1];
    }
    cout << sum << endl;
}