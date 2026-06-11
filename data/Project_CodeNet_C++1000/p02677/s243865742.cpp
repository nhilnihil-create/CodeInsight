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

    int A, B, H, M;
    cin >> A >> B >> H >> M;

    double deg_h = 30.0 * H + (30.0 * (M / 60.0));
    double deg_m = 6.0 * M;

    double deg = abs(deg_h - deg_m);
    double cosA = cos(deg * (M_PI / 180.0));
    printf("%.20lf\n", sqrt(A * A + B * B - 2 * A * B * cosA));

    return 0;
}