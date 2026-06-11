#include <bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;

int main(void){

    long long A,B,C;
    cin >> A >> B >> C;
    long long D = C - A - B; 
    string ans ="No";
    if(D > 0 && D*D > 4 * A * B)ans = "Yes";

    cout << ans <<endl;
}