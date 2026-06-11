#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A >> B;

    int ans = A - B*2;

    if(ans > 0) cout << A - B*2 << endl;
    else cout << "0" << endl;
}