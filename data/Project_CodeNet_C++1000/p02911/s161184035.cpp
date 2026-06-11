#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<long long> sum(N, Q);
    for(int i = 0; i < Q; i++){
        int a;
        cin >> a;
        a--;
        sum[a]--;
    }
    for(int i = 0; i < N; i++){
        if(K - sum[i] <= 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}