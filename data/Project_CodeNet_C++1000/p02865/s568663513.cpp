#include <iostream>
using namespace std;
int main() {
    int N; cin >> N; 
    int cnt = 0;
    for (int i = N; i > 0; i--)
    {
        if (N - i != i) cnt++;
    }
    printf("%d\n", cnt / 2);
}