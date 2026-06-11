#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    int N, X, Y;
    int index = 0;
    cin >> N >> X >> Y;
    int k[N];
    for(int i = 0; i < N; i++)
        k[i] = 0;
    for(int i = 1; i < N; i++){
        for(int j = i + 1; j <= N; j++){
            index = min(abs(X-i) + abs(Y-j) + 1, j - i);
            k[index]++;
        }
    }

    for(int i = 1; i < N; i++)
        cout << k[i] << endl;
}
