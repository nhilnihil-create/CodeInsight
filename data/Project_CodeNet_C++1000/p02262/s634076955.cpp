#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

long long ShellSort(int elem[], int num)
{
    int i, j, k;
    int h;
    int target;
    long long cnt = 0;
    vector<int> vect;

    for (h = 1; ;) {
        if (h <= num) {
            vect.push_back(h);
        }
        else {
            break;
        }
        h = 3 * h + 1;
    }

    h = vect.size() - 1;
    cout << h+1 << endl;
    for (i = h; i >= 0; i--) {
        int g = vect[i];
        if (i != h) {
            cout << " ";
        }
        cout << g;
        for (j = g; j < num; j++) {
            target = elem[j];
            for (k = j - g; k >= 0; k -= g) {
                if (elem[k] > target) {
                    elem[k + g] = elem[k];
                    ++cnt;
                }
                else {
                    break;
                }
            }
            elem[k + g] = target;
        }
    }
    cout << endl;

    return cnt;
}

int main(void)
{
    int i;
    long long cnt;
    int num;
    int elem[1000000];

    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d", &elem[i]);
    }

    cnt = ShellSort(elem, num);

    cout << cnt << endl;
    for (i = 0; i < num; i++) {
        cout << elem[i] << endl;
    }

    return 0;
}