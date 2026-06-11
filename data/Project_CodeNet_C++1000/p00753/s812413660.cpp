#include <stdio.h>
#define MAX 123456

bool p[2*MAX+1];

void prime(){
int i,j;
for(i=0; i <= 2*MAX; i++) p[i] = 1;
for(i=2; i<= MAX; i++){
if(p[i] == 0) continue;
j = i+i;
while(j <= 2*MAX){
p[j] = 0;
j += i;
}
}
}

int main(){
int n,cnt,i;

prime();
while(1){
scanf("%d", &n);
if(n == 0) break;
cnt = 0;
for(i=n+1; i <= 2*n; i++)
cnt += p[i];
printf("%d\n",cnt);
}
}