#include<bits/stdc++.h>
using namespace std;

const int max_n=1e6+10;
int a[max_n];

int gcd(int a,int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int j = 2; j <= x / j; ++j) {
            if (x % j == 0)
                m[j]++;
            while (x % j == 0) x /= j;
        }
        if (x > 1) m[x]++;
    }
    bool flag = true;
    for (auto item:m) {
        if (item.second > 1) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "pairwise coprime" << endl;
        return 0;
    }
    int g=0;
    for(int i=0;i<n;++i)
        g=gcd(a[i],g);
    if(g==1) cout<<"setwise coprime"<<endl;
    else cout<<"not coprime"<<endl;
    return 0;
}
