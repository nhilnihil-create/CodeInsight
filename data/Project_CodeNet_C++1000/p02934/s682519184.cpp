#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    double sum = 0;
    rep(i,n){
        double a;
        cin >> a;
        sum += 1/a;
    }
    printf("%.10f", 1/sum);
}