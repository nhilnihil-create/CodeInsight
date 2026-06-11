#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> L(N);
    for(int i = 0; i < N; i++) cin >> L[i];
    sort(L.begin(), L.end());
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            int t = upper_bound(L.begin() + j + 1, L.end(), L[i] + L[j] - 1) - lower_bound(L.begin() + j + 1, L.end(), L[j] - L[i] + 1);
            cnt += t;
        }
    }
    cout << cnt << endl;
}