#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int a,b;
    cin >> a >> b;
    if(a > b) swap(a,b);
    if(a==1 && b == 2) {
        cout << 3 << endl;
    } else if(a == 1 && b == 3) {
        cout << 2 << endl;
    } else if(a==2 && b == 3) {
        cout << 1 << endl;
    } 
}