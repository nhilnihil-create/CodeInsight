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
#include <set>
using ll =long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;


int main() {
    int N;
    cin >> N;
    int shou = N/1.08;
    int ans;
    while(1){
        ans = shou * 1.08;
        if(ans == N){
            break;
        }
        shou++;
        if(ans > N){
            cout << ":(" << endl;
            return 0;
        }
    }
    cout << shou << endl;
}