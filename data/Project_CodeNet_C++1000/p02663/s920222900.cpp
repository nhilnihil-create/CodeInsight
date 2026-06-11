#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

int main(){
    int h1,m1,h2,m2,k; cin >> h1 >> m1 >> h2 >> m2 >> k;
    int x1 = 60 * h1 + m1;
    int x2 = 60 * h2 + m2;

    int t = x2 - x1;
    if(t>=k){
        cout << t-k << endl;
    }else{
        cout << 0 << endl;
    }
}