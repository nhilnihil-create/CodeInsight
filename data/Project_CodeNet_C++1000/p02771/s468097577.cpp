#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int A,B,C; cin >> A >> B >> C;
    if(A==B && A!=C) cout << "Yes" << endl;
    else if(B==C && B!=A) cout << "Yes" << endl;
    else if(A==C && B!=A) cout << "Yes" << endl;
    else cout << "No" << endl;
}