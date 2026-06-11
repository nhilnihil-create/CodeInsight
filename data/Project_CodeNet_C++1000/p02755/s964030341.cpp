#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

int solve(int& A, int& B)
{
    int ans = 100001;
    for(int i = 0; i < 100001; i++)
    {
        if(floor(i*0.08)==A && floor(i*0.10)==B) ans = std::min(i, ans);
    }
    if (ans == 100001) return -1;
    else return ans;
}

int main()
{
    int A, B; std::cin >> A >> B;
    
    int ans = solve(A, B);

    std::cout << ans << std::endl;
    return 0;
}