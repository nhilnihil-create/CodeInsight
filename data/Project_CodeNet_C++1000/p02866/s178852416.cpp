#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;

using namespace std;


int main(){ 
    long long N;
    cin >> N;

    vector<int> counter(N, 0);
    int first;
    cin >> first;
    ++counter[first];

    for(int i = 1; i < N; ++i){
        int D;
        cin >> D;
        ++counter[D];
    }

    if(first != 0 || counter[0] != 1){
        cout << 0;
        return 0;
    }

    long long num = 1;
    int sum = 0;
    int prev = 1;

    for(int i = 0; i < N; ++i){
        if(counter[i] == 0){
            cout << 0;
            return 0;
        }

        for(int j = 0; j < counter[i]; ++j){
            num *= prev;
            num %= PRIME2;
        }

        prev = counter[i];
        sum += counter[i];

        if(sum == N){
            break;
        }
    }

    cout << num;
}

