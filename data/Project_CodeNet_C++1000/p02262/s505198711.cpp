#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int insertionSort(int *A, int n, int g, long cnt) {
    for (int i=g; i<n; i++) {
        int v = A[i];
        int j = i - g;
        
        while(j>=0 && A[j]>v) {
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
    
    return cnt;
}


void shellSort(int *A, int n) {
    long cnt = 0;
    // int m = (int)sqrt(n);
    // int G[m];
    vector<int> G;
    
    for (int h=1; ; ) {
        if (h > n) break;
        G.push_back(h);
        h = 3*h + 1;
    }
    
    // G[0] = (int)(n/3);
    // for (int i=0; i<m; i++) {
    //     if(i>0) G[i] = (int)(G[i-1]/3);
    //     if(i>=m-1) G[i] = 1;
    //     cnt = insertionSort(A, n , G[i], cnt);
    // }
    
    for (int i=G.size()-1; i>=0; i--) {
        cnt = insertionSort(A, n , G[i], cnt);
    }
    
    printf("%d\n", G.size());
    printf("%d", G[G.size()-1]);
    for (int i=G.size()-2; i>=0; i--) printf(" %d", G[i]);
    printf("\n");
    printf("%d\n", cnt);
}


int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    
    shellSort(a, n);
    
    for (int i=0; i<n; i++) printf("%d\n", a[i]);
    
    return 0;
}



