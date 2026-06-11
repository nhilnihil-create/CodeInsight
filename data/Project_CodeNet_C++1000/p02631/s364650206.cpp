#include <iostream>
#include <vector>
int main()
{
    int N;
    std::cin >> N;
    // long long ls[N];
    std::vector<long long> ls(N);
    long long xor_sum = 0;
    for (int i=0; i<N; i++)
    {
        std::cin >> ls[i];
        xor_sum ^= ls[i];
    }
    for (int i=0; i<N; i++)
    {
        // std::cout << (xor_sum^ls[i]) << std::endl; 
        std::cout << (xor_sum^ls[i]) << " "; 
    }
    
}