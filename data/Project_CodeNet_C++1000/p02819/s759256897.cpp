#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
    int x;
    cin >> x;

    while (1){
        for(int i=2; i<=x; i++){
            if (i == x) goto OUT;
            if (x % i == 0) break;
        }
        x++;
    }
    OUT:
    cout << x << endl;
    return 0;
}
