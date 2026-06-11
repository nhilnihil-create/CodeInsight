#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n;
    cin >> n;
    vector <long long> h(n);
    rep(i,n) cin >> h[i];

    long long tmp = h[0]-1;
    bool ok = true;
    for(int i=0; i<n; i++){
        if(tmp > h[i]){
            ok = false;
            break;
        }
        else{
            if(tmp == h[i]);
            else{
                tmp = h[i] - 1;
            }
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
