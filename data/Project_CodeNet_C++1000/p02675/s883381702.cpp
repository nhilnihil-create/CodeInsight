#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array


int n;

void solve(){

    cin >> n;

    n = n%10;
    if(n == 3){
        cout << "bon" << endl;
    }
    else if(n == 0 || n == 1 || n==6 || n==8){
        cout << "pon" << endl;
    }
    else{
        cout <<"hon" <<endl;
    }
}   





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}