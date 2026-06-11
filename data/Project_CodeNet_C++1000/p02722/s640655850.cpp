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
#include <numeric>

using namespace std;


template <typename T>
using TABLE = vector<vector<T>>;

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;


void divisor(long long N, vector<long long>& result)
{
    result.clear();
    long long max_n = sqrt(N);

    for(int i = 1; i <= max_n; ++i){
        if(N % i == 0){
            result.push_back(i);
            if(i != N / i){
                result.push_back(N / i);
            }
        }
    }
}



int main(){
    long long N;
    cin >> N;

    vector<long long> divs;
    divisor(N - 1, divs);

    long long nums = divs.size() - 1;

    divisor(N, divs);

    for(long long d : divs){
        long long r = N;

        while(r % d == 0 && d != 1){
            r = r / d;
        }

        if(r % d == 1){
            ++nums;
        }
    }

    cout << nums;
}
