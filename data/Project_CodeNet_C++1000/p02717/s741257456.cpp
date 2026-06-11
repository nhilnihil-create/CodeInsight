#include <iostream>
using namespace std;

//num1とnum2の値を入れ替える
void SwapNum(int *num1, int *num2)
{
    int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main(void)
{
    int box_A, box_B, box_C;
    cin >> box_A >> box_B >> box_C;

    SwapNum(&box_A, &box_B);
    SwapNum(&box_A, &box_C);
    cout << box_A << " " << box_B << " " << box_C << endl;
    return 0;
}
