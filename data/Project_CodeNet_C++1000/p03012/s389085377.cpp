#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n;
    cin >> n;
    int w[n]; rep(i, n){cin >> w[i];}
    int sum1=0; int sum2=0;
    int mini = 1000000000;
    for(int t = 0; t < n-1; ++t){
        for(int j = 0; j <= t; ++j){
            sum1 += w[j];
        }
        for(int j = t+1; j < n; ++j){
            sum2 += w[j];
        }
        mini = min(mini, abs(sum1-sum2));
        sum1 = 0;
        sum2 = 0;
    }
    cout << mini << endl;
}
