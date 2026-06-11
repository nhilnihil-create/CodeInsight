#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
long long cnt;
vector<int> G;
int n;
int a[1000000];

/*void algorithm3_6(vector<int> G, int A[], int N) {
    for (int i = G.size() - 1; i >= 0; i--) {
        for (int k = 0; k < N - G[i]; k++) {//对应每个i，一共要进行N-G[i]次选择排序
            int count = (k + G[i]) % G[i];
            if (G[i] == 1) {
                //当G[i]=1时，需要对整个数组进行插入排序
                for (int j = 1; j < N - 1; j++) {
                    int v = A[j];
                    for (int k = j - 1; k >= 0; k--) {
                        if (A[k] > v) {
                            A[k + 1] = A[k];
                            A[k] = v;
                            cnt++;
                        }
                    }
                }
            }
            for (int l = count + G[i]; l <= k + G[i]; l = l + G[i]) {
                int v = A[l];
                for (int m = l - G[i]; m >= 0; m = m - G[i]) {
                    if (A[m] > v) {
                        A[m + G[i]] = A[m];
                        A[m] = v;
                        cnt++;
                    }
                }
            }
        }
    }
}*/
void insertSort(int A[],int n,int g) {
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[],int n) {
    for (int h = 1;;) {
        if (h > n) {
            break;
        }
        G.push_back(h);
        h = 3 * h + 1;
    }
    for (int k = G.size()-1; k >= 0; k--) {
        insertSort(A,n,G[k]);
    }
}

int main() {
    cin >> n;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    shellSort(a,n);
    cout << G.size() << endl;
    for (int i = G.size() - 1; i >= 0; i--) {
        printf("%d",G[i]);
        if (i) {
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n",cnt);
    for (int j = 0; j < n; j++) {
        printf("%d\n",a[j]);
    }
    return 0;
}
