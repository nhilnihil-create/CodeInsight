#include<cstdio>

#define MAX_N 10000
#define MAX_Q 500

using namespace std;

int S[MAX_N + 5], T[MAX_Q + 5];

bool searchS(int x, int length)
{
    int place = 0;
    S[length] = x;
    while (true) {
        if (S[place] == x) {
            break;
        }
        else {
           place++;
        }
    }
    if (place < length) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int n, q, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &T[i]);
        if (searchS(T[i], n)) {
            sum++;
        }
    }
    printf("%d\n", sum);

    return 0;
}