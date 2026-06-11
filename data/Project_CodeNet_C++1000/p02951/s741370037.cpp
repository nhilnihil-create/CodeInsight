#include <iostream>

using namespace std;

int main(void)
{
    int A, B, C, tmp, answer;
    cin >> A >> B >> C;
    tmp = A - B;
    answer = C - tmp;
    if (answer < 0)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << answer << endl;
    }
}