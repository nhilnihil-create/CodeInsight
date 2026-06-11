#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

#define ll long long

int main()
{
    std::string S, T;
    std::cin >> S >> T;

    int s_size = S.size();
    int t_size = T.size();
    int ans = t_size;
    for(int i=0; i < (s_size-t_size+1); i++) {
        int tmp = 0;
        for(int j=0; j < t_size; j++) {
            if(S[i+j] != T[j]) {
                tmp++;
            }
        }
        ans = ans > tmp ? tmp : ans;
        if (ans == 0) {
            break;
        }
    }
    std::cout << ans << std::endl;
}