#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
const int MAX_N=200000;
 int N;
 int A[MAX_N],AC[MAX_N],S[MAX_N];
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
        AC[i]=A[i];
    }
    sort(AC,AC+N,greater<int>());
    for(int j=0;j<N;j++){
        if(AC[0]==A[j]){
            int An=AC[1];
            printf("%d\n",An);
        }else{
            int An=AC[0];
            printf("%d\n",An);
        }
    }
}