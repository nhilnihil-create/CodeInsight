#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    return ((a % b) ? gcd(b, a % b) : b);
}

int main(void)
{
    int K;
    cin >> K;

    int count = 0;
    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= K; j++){
            for(int k = 1; k <= K; k++){
                count += gcd(i, gcd(j, k));
            }
        }
    }
    cout << count << endl;

        return 0;
}
