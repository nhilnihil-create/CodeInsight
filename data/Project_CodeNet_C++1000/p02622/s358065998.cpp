#include <iostream>
#include <cstdlib>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main(void)
{
    string S, T;
    cin >> S;
    cin >> T;

    int ans = 0;
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] != T[i]) ++ans;
    }

    cout << ans;
    
    return 0;
}
