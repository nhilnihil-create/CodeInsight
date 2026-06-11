#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    if(n % 2 == 0) printf("%.10f", 0.5);
    else printf("%.10f", (double)((n+1)/2)/(double)n);
}