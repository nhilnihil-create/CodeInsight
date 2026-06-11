#include <iostream>
#include <map>
#include <vector>
using namespace std;
long long nChoosek( long long n, long long k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    long long result = n;
    for( long long i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
int main(){
    long long n;cin>>n;
    vector<long long> balls(n);for (long long i=0;i<n;i++){cin>>balls[i];};
    map<long long, long long> counter;
    for (auto b : balls){
        if (counter.find(b) == counter.end()){
            counter[b] = 1;
        } else {
            counter[b]++;
        }
    }

    map<long long, long long> memo;
    long long base_number = 0;
    for (auto freq : counter){
        memo[freq.first] = nChoosek(freq.second, 2);
        base_number += memo[freq.first];
    }

    for (auto ball : balls){
        if (memo[ball] == 0){
            cout << base_number << endl;
        } else {
            cout << base_number - memo[ball] + nChoosek(counter[ball]-1, 2) << endl;
        }

    }


}