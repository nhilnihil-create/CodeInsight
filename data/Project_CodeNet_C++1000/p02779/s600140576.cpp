#include <bits/stdc++.h>
using namespace std;
int A[210000];
int main(void){
    int N;scanf("%d",&N);
 for(int i=0;i<N;i++)scanf("%d",A+i);
sort(A,A+N);
 for(int i=0;i<N-1;i++){
 if(A[i]==A[i+1]){
 printf("NO\n");return 0;
 }
 }
 printf("YES\n");
}