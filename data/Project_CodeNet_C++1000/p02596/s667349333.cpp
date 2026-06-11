#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;

int main() {
    int k;
    cin >> k;
    set<int> s;
    int a=7%k;
    int n=1;
    while (s.count(a)==0) {
        if (a%k==0) {
            cout << n << endl;
            return 0;
        }
        s.insert(a);
        a=(a*10+7)%k;
        n++;
    }
    cout << -1 << endl;
    return 0;
}