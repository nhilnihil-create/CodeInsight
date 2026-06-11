#include <bits/stdc++.h>
using namespace std;


char S[110];
char T[110];
int main(){
    int a;scanf("%d",&a); 
    scanf("%s%s",S,T);
    for(int i=0;i<a;i++)printf("%c%c",S[i],T[i]);printf("\n");
}