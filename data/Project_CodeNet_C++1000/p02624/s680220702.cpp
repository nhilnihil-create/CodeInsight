#include <iostream>
 
int main()
{
    long long N;
    std::cin >> N;
    long long ans = 0;
    for (long long i=1; i<N+1; i++)
    {
        long long n = N/i;
        ans += i*(n*(n+1))/2;
    }
    std::cout << ans;
}