#include<bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n;
    cin >> n;
    int d[n];
    rep(i, n){cin >> d[i];}
    int cnt = 0;
    rep(i, n-1){
        for(int j = i+1; j<n; j++){
            cnt += d[i]*d[j];
        }
    }
    cout << cnt << endl;
}