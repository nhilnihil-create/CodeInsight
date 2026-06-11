#include <iostream>
using namespace std;

int main()
{
    int rect_side_01 = 0;
    int rect_side_02 = 0;

    cin >> rect_side_01 >> rect_side_02;

    int area = rect_side_01 * rect_side_02;
    int sum_side = 2*rect_side_01 + 2*rect_side_02;

    cout << area << " " << sum_side << endl;

    return 0;
}