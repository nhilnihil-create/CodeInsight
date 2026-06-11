#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmax(T& a, T b){
    a = max(a, b);
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int64_t money = 1000;
    pair<int64_t, int64_t> kabu;
    for(int a : A){
        chmax(money, kabu.first*a + kabu.second);
        chmax(kabu, {money/a, money%a});
    }
    cout << money << endl;
    return 0;
}
