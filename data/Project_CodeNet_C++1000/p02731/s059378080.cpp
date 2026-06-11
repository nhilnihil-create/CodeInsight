#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;

int main(){
    double l;cin>>l;
    double edge = l / 3;
    double ans = edge * edge * edge;
    printf("%.7lf", ans);
    return 0;
}
