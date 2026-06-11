#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstdint>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long i64;
typedef vector<int> ivec;
typedef vector<string> svec;

//?????°?????£?¨?
i64 cnt = 0;
int l;
int A[1000000];
int N;
ivec G;

//??¢??°??????
void insertionSort(int A[], int N, int g){
    for (int i=g; i<N; i++){
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[], int N){
    for (int h = 1;;){
        if (h > N) break;
        G.push_back(h);
        h = 3*h + 1;
    }

    for (int i=G.size()-1; i>=0; i--){
        insertionSort(A, N, G[i]);
    }
}




int main(){
    //?????????????????????
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &A[i]);

    //?????????


    //??¢?????´?????????
    shellSort(A, N);


    //??????
    printf("%d\n", G.size());

    for(int i = G.size()-1; i>=0; i--){
        if (i != G.size()-1) printf(" ");
        printf("%d", G[i]);
    }
    printf("\n");
    
    printf("%d\n", cnt);

    for(int i=0; i<N; i++) printf("%d\n", A[i]);


    return 0;
}