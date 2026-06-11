#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
    cout << "print_vector -> ";
    for(int i=0; i<vec.size(); i++) {
        if(i == vec.size()-1) {
            cout << vec[i] << endl;
        }
        else {
            cout << vec[i] << " ";
        }
    }
    return;
}

int main() {

    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for(int i=0; i<N; i++) cin >> H[i];
    vector<int> A(M);
    vector<int> B(M);
    for(int i=0; i<M; i++) cin >> A[i] >> B[i];
    
    vector<bool> data(N, true);

    for(int i=0; i<M; i++) {
        if(H[A[i]-1] >= H[B[i]-1]) {
            data[B[i]-1] = false;
        }
        if(H[A[i]-1] <= H[B[i]-1]) {
            data[A[i]-1] = false;
        }
    }

    int result = 0;
    for(auto&& d : data) {
        if(d) result++;
    }

    cout << result << endl;

    return 0;
}