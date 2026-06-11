#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int N, A[250];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    for (int i = 0; i < N; i++) {
        int num, key, parentKey, leftKey, rightKey;
        num = i + 1;
        key = A[i];
        parentKey = (num / 2) - 1;
        leftKey = (num * 2) - 1;
        rightKey = (num * 2);
        
        printf("node %d: key = %d, ", num, key);
        
        if (parentKey >= 0 && parentKey < N) {
            printf("parent key = %d, ", A[parentKey]);
        }
        if (leftKey >= 0 && leftKey < N) {
            printf("left key = %d, ", A[leftKey]);
        }
        if (rightKey >= 0 && rightKey < N) {
            printf("right key = %d, ", A[rightKey]);
        }

        cout << endl;
    }

    return 0;
}

