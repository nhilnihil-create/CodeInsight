#include <bits/stdc++.h>
using namespace std;
int main(void){
    int X;
    cin >> X;
    int dai = (X/500)*1000;
    int syo = (X%500/5)*5;
    int ans = dai + syo ;
    cout << ans << endl;
}