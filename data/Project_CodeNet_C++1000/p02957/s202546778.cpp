#include <bits/stdc++.h>
using namespace std;
 
string S; int N, cnt;
 
int main() {
	int A,B;
    cin >> A >> B;
    if(A-B==0)cout << "0" << endl;
    else if((A+B)%2==0)cout << (A+B)/2 << endl;
    else cout << "IMPOSSIBLE" << endl;
}