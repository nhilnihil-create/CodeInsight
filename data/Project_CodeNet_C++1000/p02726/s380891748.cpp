#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int N, X, Y;
    std::cin >> N >> X >> Y;
    // |-------------------+--------------+----------------|
    //                     +--------------+
    //   i           j                                           : j-i
    //                i      j                                   : min(j-i, |X-i|+|Y-j|+1)
    //                         i       j                         : min(j-i, |X-i|+|Y-j|+1)
    //                         i                j                : min(j-i, |X-i|+|Y-j|+1)
    //                                              i  j         : j-i
    // forall i,j. count[d(i, j)]に1足す
    // count[k]
    std::vector<int> count(N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            int d = std::min(j - i, std::abs(X - i) + std::abs(Y - j) + 1);
            count[d]++;
        }
    }
    for (int k = 1; k <= N - 1; k++)
    {
        std::cout << count[k] << std::endl;
    }
}