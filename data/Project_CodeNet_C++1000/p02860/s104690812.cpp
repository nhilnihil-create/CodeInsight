#include <bits/stdc++.h>
#define rep(a,b) for(int a =0 ;a<b; a++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    if(n%2 != 0){
        cout << "No";
        return 0;
    }
    string s;
    cin >> s;
    string z = s.substr(0,n/2), y = s.substr(n/2,n/2);
    if(z == y)cout << "Yes";
    else cout << "No";
}
