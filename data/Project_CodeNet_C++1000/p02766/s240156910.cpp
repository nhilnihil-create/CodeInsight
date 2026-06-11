#include <iostream>

using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    int count = 0;
    while(N != 0){
        int d = N % K;
        N -= d;
        N /= K;
        count++;
    }
    cout << count << endl;
}