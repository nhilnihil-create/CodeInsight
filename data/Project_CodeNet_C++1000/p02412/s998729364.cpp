// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int main()
{
    int n, x, ans;
    while(true){
        std::cin >> n >> x;
        ans = 0;
        if (n == 0 && x == 0){
            break;
        }
        else if (x < 6){
            std::cout << "0" << endl;
        }
        else {
            for (int i=1; i<=n; ++i){
                for (int j=i+1; j<=n; ++j){
                    if (x-i-j > j && x-i-j <= n && x-i-j != i && x-i-j != j){
                        ans++;
                        // std::cout << i << "+" << j << "+" << x-i-j << endl;
                    }
                }
            }
            std::cout << ans << endl;
        }
    }
    return 0;
}

