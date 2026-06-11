#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void print(int *begin, int *end)
{
    for (int *i = begin; i != end; i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

bool back(int *begin, int *end)
{
    int *i = end - 1;
    while (i != begin)
    {
        // 順番がおかしいものを発見
        if (*(i - 1) > *i)
        {
            int *j = i;
            while (j != end)
            {
                if (*j > *(i - 1))
                    break;
                j++;
            }
            swap(*(i - 1), *(--j));
            std::reverse(i, end);
            return true;
        }
        i--;

        //print(begin, end);
    }

    return false;
}

int n;
int p[8];
int q[8];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> q[i];

    int a = 0;
    int b = 0;
    do
    {
        a++;
    } while (back(p, p + n));
    do
    {
        b++;
    } while (back(q, q + n));

    cout << abs(a - b) << endl;
}