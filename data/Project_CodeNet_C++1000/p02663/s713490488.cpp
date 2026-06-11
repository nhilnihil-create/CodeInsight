#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main(){
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    printf("%d\n",max((c-a)*60+d-b-e,0));
    return 0;
}