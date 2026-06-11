#include <cstdio>
#include <vector>
using namespace std;
#define NMAX 1000000

void printArr(int A[], int N){
    for(int i = 0; i < N; ++i){
        printf("%d\n", A[i]);
    }
}

void printG(vector<int> v){
    int N = v.size();
    for(int i = N - 1; i >= 1; --i){
        printf("%d ", v[i]);
    }
    printf("%d\n", v[0]);
}

long long insertionSort(int A[], int g, int N){
    long long cnt = 0;
    
    for(int i = g; i < N; ++i){
        int tmp = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > tmp){
            A[j + g] = A[j];
            j -= g;
            ++cnt;
        }
        A[j + g] = tmp;
    }

    return cnt;
}

void shellSort(int A[], int N){
    int m;
    long long cnt = 0;
    vector<int> G;

    for(int g = 1; g <= N; g = 3 * g + 1){
        G.push_back(g);
    }
    m = G.size();

    printf("%d\n", m);
    printG(G);

    for(int i = m - 1; i >= 0; --i){
        cnt += insertionSort(A, G[i], N);
    }

    printf("%lld\n", cnt);
    printArr(A, N);
}

int main(){
    int N;
    static int A[NMAX];

    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", &A[i]);
    }

    shellSort(A, N);

    return 0;
}
