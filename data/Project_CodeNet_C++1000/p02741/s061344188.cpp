#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
    const vector<int> l = {
        1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14,
        1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51
    };

    int k;
    cin >> k;
    cout << l[k - 1] << endl;
}
