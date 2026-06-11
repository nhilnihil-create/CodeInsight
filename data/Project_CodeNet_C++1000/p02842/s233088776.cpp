#include <bits/stdc++.h>
using namespace std;
int inf = 1000000000; //10e9
 
int main() {
    
    int N, ans = 0;
    cin >> N;

    int cost_ceil = ceil(N/1.08);
    int cost_floor = floor(N/1.08);
    int ceil_init = cost_ceil*1.08;
    int floor_init = cost_floor*1.08;

    if(ceil_init == N || floor_init == N){
        if(ceil_init == N){
            cout << cost_ceil << endl;
        } else {
            cout << cost_floor << endl;
        }
    } else {
        cout << ":(" << endl;
    }

    return 0;
}