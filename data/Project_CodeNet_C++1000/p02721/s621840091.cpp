#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, c; cin >> n >> k >> c;
    int l[k], r[k];
    string s; cin >> s;
    for (int i=0, t = 0; i<n && t<k; i++){
        if (s[i] == 'o'){
            l[t++] = i;
            i += c;
        }
    }
    for (int i=n-1, t=k-1; i>=0 && t>=0; i--){
        if (s[i] == 'o') {
            r[t--] = i;
            i -= c;
        }
    }
    for (int i=0; i<k; i++){
        if (l[i] == r[i]) cout << l[i] +1<< endl;
    }
}