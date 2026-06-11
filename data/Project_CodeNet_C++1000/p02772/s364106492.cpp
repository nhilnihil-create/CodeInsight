#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <functional>
#include <math.h>
#include <iomanip>
using namespace std;

int main(void)
{
    long N;
    cin >> N;

    int max = 0;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp % 2 == 0 && (tmp % 3 != 0 && tmp % 5 != 0))
        {
            cout << "DENIED" << endl;
            return 0;
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}