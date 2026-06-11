#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

long long int solve(long long int& N, long long int& A, long long int& B)
{
    long long int residual = N % (A + B);
    long long int ans = (N - residual) / (A + B);
    ans *= A;
    if(residual >= A) ans += A;
    else ans += residual;

    return ans;
}

int main()
{
    long long int N, A, B; std::cin >> N >> A >> B;

    long long int ans = solve(N, A, B);

    std::cout << ans << std::endl;
    
    return 0;
}