#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
using ll =long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    if((B-A)%2 == 0){
        cout << (B-A)/2 << endl;
    }
    else{
        cout << min(A-1, N-B) + 1 + (B-A-1)/2 << endl;
    }
    
}