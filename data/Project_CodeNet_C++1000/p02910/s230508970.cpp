#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
const int maxn = 200007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    f(s.size()) {
        if(i % 2 == 0 && s[i] == 'L') {
            cout << "No\n";
            exit(0);
        }
        if(i % 2 == 1 && s[i] == 'R') {
            cout << "No\n";
            exit(0);
        }
    }
    cout << "Yes\n";
}  