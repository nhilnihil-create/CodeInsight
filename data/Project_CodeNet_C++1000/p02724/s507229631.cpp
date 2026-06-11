#include<bits/stdc++.h>

using namespace std;

int main(){
    int x;scanf("%d",&x);
    int t=x/500;
    x-=t*500;
    x/=5;
    printf("%d",t*1000+x*5);

    return 0;
}
