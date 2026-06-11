#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
   	res.erase(res.begin());
    return res;
}
long long calc(long long N, long long K)
{
	if(N % K == 0) return calc(N/K,K);
	else return N % K;
}
int main() {
    long long N;
    cin >> N;
    long long answer = 0;
    const auto &res = enum_divisors(N);
    for (long long i = 0; i < res.size(); i++)
    {
    	if ( calc(N,res[i]) == 1 ) answer += 1;
    }
    const auto &res2 = enum_divisors(N-1);
    answer += res2.size();
    cout << answer << endl;
    return 0;
}