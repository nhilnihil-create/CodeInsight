#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main(void){
    int n; cin >> n;
    int x[n]; rep(i, n){cin >> x[i];}
    int sum = 0;
    int mini = 100000000;
    for(int i = 1; i <= 100; ++i){
        rep(j, n){
            sum += (i - x[j]) * (i - x[j]);
        }
        mini = min(mini, sum);
        sum = 0;
    }
    
    cout << mini << endl;
    return 0;
}
