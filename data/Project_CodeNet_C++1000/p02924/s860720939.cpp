#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    cout << (long long) N*(N-1)/2 << endl;
    return 0;
}