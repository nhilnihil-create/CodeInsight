#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int heap[250];
int H;

int parent(int i)
{
    return i / 2;
}

int left(int i)
{
    return 2 * i;
}

int right(int i)
{
    return 2 * i + 1;
}
int main()
{
    cin >> H;
    for (int i = 1; i <= H; i++)
        cin >> heap[i];

    for (int i = 1; i <= H; i++)
    {
        printf("node %d: key = %d, ", i, heap[i]);
        if (parent(i) > 0)
            printf("parent key = %d, ", heap[parent(i)]);
        if (left(i) <= H)
            printf("left key = %d, ", heap[left(i)]);
        if (right(i) <= H)
            printf("right key = %d, ", heap[right(i)]);
        printf("\n");
    }
    return 0;
}
