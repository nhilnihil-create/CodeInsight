#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for(int i = 0; i <= x; ++i){
        ans = 2*i + 4*(x-i);
        if(ans == y){
            cout << "Yes" << endl;
            return 0;
            
        }
    }
    cout << "No" << endl;
    return 0;
}