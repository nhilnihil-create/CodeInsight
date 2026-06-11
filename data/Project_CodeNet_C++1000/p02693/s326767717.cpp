#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,a,b;
    cin >> k >> a  >> b;
    cout << (b-(b%k)>=a?"OK":"NG");
    return 0;
}