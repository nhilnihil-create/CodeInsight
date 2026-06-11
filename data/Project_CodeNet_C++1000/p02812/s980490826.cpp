#include <cstdio>
#include <cmath>
#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdint>
#include <functional>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;

const ll mod = 1000000000 + 7; //10^9


// bool is_integer(double x){
//     return floor(x) == x;
// }

// vector<int> bitsearch(int n, int bit) {
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> S(n);
//         if(bit & (1 << i)){
//             S.push_back(i);
//         }
//     }
// }./  

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int a = S.size();
    int ans = 0;
    for (int i = 0; i < a - 2; i++)
    {
        if (S[i] == 'A')
        {
            if (S[i + 1] == 'B' )
            {
                if (S[i + 2] == 'C')
                {
                    ans ++;
                }
                
            }
            
        }
        
    }
    cout << ans << endl;
    
}