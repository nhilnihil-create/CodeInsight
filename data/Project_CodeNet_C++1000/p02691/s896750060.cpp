#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    long long N;
    std::cin >> N;

    std::vector<long long> A(N);
    for (long long i=0; i<N; i++) 
        std::cin >> A.at(i);

    long long ans = 0;
    // {}で0で初期化
    // https://tt4cs.hatenadiary.org/entry/20120219/1329636595
    long long cnt[200005] = {};
    for (int i=0; i<N; i++)
    {
        // j-A_j==i+A_i. j-A_j<=N, i+A_i>0
        if (i-A.at(i)>0) ans += cnt[i-A.at(i)];
        
        // i+A_i>Nは考えなくていい
        if (i+A.at(i)<=N) cnt[i+A.at(i)]++;
    }
    std::cout << ans;

}