#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}
const int mod = 1000000007;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int sum = a+b+c;
    if(sum >= 22) cout << "bust" << endl;
    else cout << "win" << endl;
}