#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int i,j;
    i=(c+b-1)/b;
    j=(a+d-1)/d;
    if(i<=j)printf("Yes");
    else printf("No");
}
