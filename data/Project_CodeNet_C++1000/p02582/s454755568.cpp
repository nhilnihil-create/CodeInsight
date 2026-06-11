#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;
using ll = long long;

int main(){
    string S;
    cin >> S;
    int ans=0;
    if(S=="RRR") cout << 3 << endl;
    else if(S=="RRS" || S=="SRR") cout << 2 << endl;
    else if(S=="SSS") cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}