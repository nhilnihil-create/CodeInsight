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
    string T;
    cin >> T;

    for(ll i=0; i<T.size(); i++){
        if(T.at(i) == '?'){
            T.at(i) = 'D';
        }
    }
    cout << T << endl;
}