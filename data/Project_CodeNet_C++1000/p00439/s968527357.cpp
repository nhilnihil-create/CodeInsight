#include <stdio.h>
int RB[100005],ans;
int main() {int N,K,i,j;while (1) {scanf("%d %d",&N,&K);if (!N || N==EOF) return 0;ans=-1000000007,j=0;for (i=0,K--;i<K;i++) scanf("%d",&RB[i]),j+=RB[i];for (i=K;i<N;i++) scanf("%d",&RB[i]),j+=RB[i],(ans=(ans>j)?ans:j),j-=RB[i-K]; printf("%d\n",ans);}}