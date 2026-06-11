#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

int n, k, tmp;
string s;




void solve(){
    

    cin >> n;
    
    if(n%1000 == 0) cout << "0" << endl;
    else
        cout <<  1000-(n % 1000) << "\n";

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}