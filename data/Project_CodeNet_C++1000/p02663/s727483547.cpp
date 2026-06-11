#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main(){
    int h1, m1, h2, m2, k;
    cin >>  h1 >> m1 >> h2 >>  m2 >> k;
    int hm1 = h1*60 + m1;
    int hm2 = h2*60 + m2;

    cout << hm2 -hm1-k  << endl;
    return 0;
}