#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

using namespace std;

const int m = 1000;

int main(){
    ios::sync_with_stdio(false);
    int x; cin >> x;

    for(int a = 0; a<m;a++){
        for (int b=(-1)*m;b<m;b++){
            if(pow(a,5)-pow(b,5) == x){
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }

    return 0;
}