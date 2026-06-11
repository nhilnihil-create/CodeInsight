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

    if(N % 2 == 0){
        cout << N / 2 - 1;
    }
    else{
        cout << N / 2;
    }
}

