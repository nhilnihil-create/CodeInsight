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

    int X, N;
    cin >> X >> N;

    vector<int> p(N);
    for(int i=0; i<N; i++) cin >> p[i];

    if(N == 0) {
        cout << X << endl;
        return 0;
    }

    int min = 100000;
    int result = -1;
    for(int i=-100; i<=101; i++) {
        if(find(p.begin(), p.end(), i) == p.end()) {
            int temp = abs(i - X);
            if(temp < min) {
                min = temp;
                result = i;      
            }
        }
    }

    cout << result << endl;

    return 0;
}