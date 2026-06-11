#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    while(n>0){
        n /= k;
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}