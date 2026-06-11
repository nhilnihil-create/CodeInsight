#include <bits/stdc++.h>
#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;

typedef long long ll;
using namespace std;

int main(){
    io

    int a,b,c;
    cin >> a >> b >> c;
    cout << c - min(a-b,c) << ENDL;
 
    return 0;
}