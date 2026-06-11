#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string S;
    cin >> S;
    sort(S.begin(),S.end());
    if(S.at(0)==S.at(1)&&S.at(2)==S.at(3)&&S.at(0)!=S.at(3))cout << "Yes" << endl;
    else cout << "No" << endl;
}