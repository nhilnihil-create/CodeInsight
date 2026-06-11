#include <iostream>

template <typename T>
bool chmax(T &a, const T &b) {
    if (a < b) {
      a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b) {
    if (a > b) {
      a = b;
      return true;
    }
    return false;
}

int main() {
    using namespace std;
    int N;
    cin >> N;
    int plus_max = -2e9, minus_max = -2e9, plus_min = 2e9, minus_min = 2e9;
    for(int i = 0; i < N; i++){
        int A, B;
        cin >> A >> B;
        chmax( plus_max, A + B );
        chmax( minus_max, A - B );
        chmin( plus_min, A + B );
        chmin( minus_min, A - B );
    }
    cout << max( plus_max - plus_min, minus_max - minus_min ) << '\n';
}