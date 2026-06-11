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
    int K;
    cin >> K;

    string S;
    cin >> S;

    for (int i = 0; i < min(K, (int)S.size()); ++i)
    {
        cout << S[i];
    }
    if (S.size() > K) cout << "...";

    return 0;
}
