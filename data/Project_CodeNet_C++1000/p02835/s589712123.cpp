#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    int ans = A + B + C;
    if(ans >= 22){
        cout << "bust" << '\n';
    }else{
        cout << "win" << '\n';
    }
    return 0;
}