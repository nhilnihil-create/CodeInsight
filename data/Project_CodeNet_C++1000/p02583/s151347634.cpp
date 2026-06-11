#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int L[110];

    for(int i = 0; i < N; i++) {
        cin >> L[i];
    }
    sort(L, L+N);

    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            for(int k = 0; k < j; k++) {
                if(L[k] != L[j] && L[i] != L[j] && L[k]+L[j]>L[i]) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}