#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;
int K,X;
int main(){
    cin >> K >> X;
    for(int i = (-1)*K+1;i<K;i++){
        int A = X + i;
        printf("%d ",A);
    }
    printf("\n");
}