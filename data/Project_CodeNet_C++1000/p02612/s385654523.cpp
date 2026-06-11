#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >>n;
    int k = n/1000 + (n%1000 > 0);
    cout <<1000*k - n <<endl;

    return 0;
}
