#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i< int (n); i++)
using namespace std;
typedef long long ll;

int main(){

string n;
cin >> n;
int sum=0;
rep(i,n.size()) sum += n[i]-'0';
if(sum%9==0) cout << "Yes" << endl;
else cout << "No" << endl;

}