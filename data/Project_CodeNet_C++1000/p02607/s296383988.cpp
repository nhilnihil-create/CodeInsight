#include <iostream>

using namespace std;


int main()
{
    int squares[100], squares_num, answer = 0;
    cin >> squares_num;
    for (int i = 0; i < squares_num; i++)
    {
        cin >> squares[i];
    }
    for (int z = 0; z < squares_num; z+=2)
    {
        if (squares[z] % 2 == 1)
            answer++;
    }
    cout << answer;
}