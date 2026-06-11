#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    int sum = 0;
    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
        sum ^= a[i];
    }
    for(int i = 0; i < N; ++i){
        cout << (a[i]^sum) << endl;
    }
    return 0;
}