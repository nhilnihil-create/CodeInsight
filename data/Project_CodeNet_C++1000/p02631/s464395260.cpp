#include<iostream>
#include<cstdio>
using namespace std;
const int N = 200005;
int a[N];
int main() {
    int n, X = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
        X ^= a[i];
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d ",X^a[i]);
    }
return 0;
}