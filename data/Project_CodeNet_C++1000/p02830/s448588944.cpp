#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;


int main(){
    io

    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;

    for(int i(0); i<n; i++){
        cout << a[i];
        cout << b[i];
    }

    return 0;
}