#include <iostream>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long K;
    cin >> K;
    int x = 0;
    int count;
    for (count = 0; count < K; count++) {
        x = (x * 10 + 7) % K;
        if (x == 0)
            break;
    }
    
    if (count == K)
        cout << -1;
    else
        cout << count + 1 ;
}