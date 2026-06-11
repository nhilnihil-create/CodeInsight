#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main(){
    int k, x;
    cin >> k >> x;
    
        int cnt = x - k + 1;
        rep(_,2*k-2){
            cout << cnt << " ";
            cnt++;
        }
        cout << cnt << endl;
    

}
