#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main(){
    int x; cin >> x;
    for(int i = x ; i <= 100003; i++){
        bool flag = true;
        for(int j = 2; j <= i / 2; j++){
            if(i % j == 0) flag = false;
        }
        if(flag){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
