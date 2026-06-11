#include <iostream>
using namespace std;

int main() {
    int N, K, S;
    cin >> N >> K >> S;
    //S<1e9 のとき、S,S,…,S,S+1,…,S+1(SがK個)(l≥Kに対しては区間和がSにならないようにする必要があるので、残りはS+1とかで埋めておく)
    //S=1e9 のとき、S,S,…,S,1,…,1(SがK個)
    int rem = S+1;
    if (rem > 1e9) rem = 1;
    for (int i = 0; i < K; ++i) cout << S << " ";
    for (int i = K; i < N; ++i) cout << rem << " ";
    cout << endl;
}
//lとr同じでいいからね