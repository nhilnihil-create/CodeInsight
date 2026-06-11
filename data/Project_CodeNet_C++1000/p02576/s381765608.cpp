#include<bits/stdc++.h>
using namespace std;
using Long = long long;

int main(){
    int n , x ,t ;
    scanf("%d %d %d",&n,&x,&t);
    printf("%d", (n + x - 1) / x * t );
    return 0;
}