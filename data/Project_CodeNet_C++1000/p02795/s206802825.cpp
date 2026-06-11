#include <bits/stdc++.h>
using namespace std;

int main() {
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    printf("%d\n",(n+max(h,w)-1)/max(h,w));
}