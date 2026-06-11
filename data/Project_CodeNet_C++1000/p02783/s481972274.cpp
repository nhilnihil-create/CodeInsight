#include<bits/stdc++.h>
using namespace std;

int main(){
    int H, A;
    cin >> H >> A;
    int cnt = H / A;
    if(H % A != 0) cnt++;
    cout << cnt << endl;
}