#include <iostream>

using namespace std;

int main(void)
{
    int N, D, watch, answer = 1;
    cin >> N >> D;
    watch = 2 * D + 1;
    while (answer * watch < N)
    {
        answer++;
    }
    cout << answer << endl;
}