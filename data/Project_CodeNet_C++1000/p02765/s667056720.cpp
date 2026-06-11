#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    int n,r;
    cin >> n >> r;
    if(n<=9){
        int de = 100*(10-n);
        cout << r + de << endl;
    }else{
        cout << r << endl;
    }
}