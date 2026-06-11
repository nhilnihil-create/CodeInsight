#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

long long cnt = 0;
int A[1000000];
vector<int> G;


void shellSort(int A[], int n) {
    /*int h = 1;
    while(h < n) {
        G.push_back(h);
        h = h * 3 + 1;
    }*/
    //int h = 1;
    //while(h < n/3) h = 3*h + 1;

    for(int h = 1; ;) {
        if(h > n) break;
        G.push_back(h);
        h = 3*h + 1;
    }

    for(int m = G.size()-1; m >= 0; m--) {
        int h = G[m];
        for(int i = h; i < n; i++) {
            for(int j = i; j >=h && A[j] < A[j-h]; j = j-h) {
                int temp = A[j];
                A[j] = A[j-h];
                A[j-h] = temp;
                cnt++;
            }
        }
    }

}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    cnt = 0;
    shellSort(A, n);

    cout << G.size() << endl;

    for(int i = G.size()-1; i >=0; i--) {
        printf("%d", G[i]);
        if(i) printf(" ");
    }
    printf("\n");

    printf("%d\n", cnt);

    for(int i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }
    return 0;
}