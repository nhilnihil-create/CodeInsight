#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string t;
    cin >> t;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '?'){
            t[i] = 'D';
        }
    }
    cout << t << endl;
}
