#include <bits/stdc++.h>
#define rep(i,n)  for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define deb(x) cerr << #x <<": " << x << '\n';
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long double ld;
typedef long long ll;

int main(){
    ios;
    int a,b,c;
    cin >> a >> b >> c;
    cout << (( (c - (a-b)) > 0)? (c - (a-b)) : 0);
    return 0;
}
