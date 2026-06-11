#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll INF = 1LL<<60;
/////////////////////////////////
int main(){
    int n;
    cin >> n;
    bool can = false;
    for (int i = 1; i < 10;i++)
        for (int j = 1; j < 10;j++)
        if(n==i*j)
            can = true;
            
            if (can)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
}