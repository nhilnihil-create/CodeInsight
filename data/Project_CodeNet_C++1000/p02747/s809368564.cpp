#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;

int main(){
    string S;
    cin >> S;
    string hi;
    if(S.size()%2!=0){
        cout << "No" << endl;
        return 0;
    }
    rep(i, S.size()/2){
        hi += "hi";
    }
    if(S==hi) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
