#include <iostream>
using namespace std;

void outerLoop(int i);
void innerLoop(int i, int j);

static const int MAX = 9;

int main()
{
    outerLoop(1);
}

void outerLoop(int i)
{
    if (MAX < i) {
        return;
    }
    innerLoop(i, 1);
    outerLoop(i + 1);
}

void innerLoop(int i, int j)
{
    if (MAX < j) {
        return;
    }
    cout << i << "x" << j << "=" << i * j << endl;;
    innerLoop(i, j + 1);
}