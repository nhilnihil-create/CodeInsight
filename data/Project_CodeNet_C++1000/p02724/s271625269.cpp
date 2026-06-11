#include <bits/stdc++.h>
using namespace std;
int main(){
    int X;
    cin >> X;
    int A = X/500;
    int B=(X-A*500)/5;
    int Ans = A*1000+B*5;
    cout << Ans << endl;
}
