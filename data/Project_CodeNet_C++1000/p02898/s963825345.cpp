#include<bits/stdc++.h>
#include <algorithm>
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
    int h[n]; rep(i, n){
        cin >> h[i];
        if(h[i] >= k){++cnt;}
    }
    cout << cnt << endl;
}