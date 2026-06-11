#include <bits/stdc++.h>
using namespace std;
 
string S; int N, cnt;
 
int main() {
	int A,B;
    cin >> A >> B;
    int Ans;
    if((B-1)%(A-1)==0)Ans = (B-1)/(A-1);
    else Ans = (B-1)/(A-1)+1;
    cout << Ans << endl;
}