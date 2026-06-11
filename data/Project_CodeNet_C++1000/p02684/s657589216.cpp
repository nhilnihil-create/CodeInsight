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

    int N;
    unsigned long long K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    vector<int> data(N+1);
    vector<bool> find_map(N+1, false);

    int point = 1;
    unsigned long long count = 0;
    int loop_start = -1;
    int loop_end = -1;
    int loop_town = -1;
    for(int i=0; i<N; i++) {
        if(find_map[point]) {
            loop_end = i;
            loop_town = point;
        }
        data[i] = point;
        find_map[point] = true;
        point = A[point-1];
    }

    for(int i=0; i<N; i++) {
        if(data[i] == loop_town) {
            loop_start = i + 1;
            break;
        }
    }

    unsigned long long index;
    if(K < loop_start) {
        index = K;
    }
    else {
        index = (K - loop_start) % (loop_end - loop_start + 1) + loop_start;
    }

    cout << data[index] << endl;

    return 0;
}