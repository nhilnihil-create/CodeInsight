#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    double ans = 0;
    for(int i = 0; i < n; i++)
        ans += 1 / a[i];
    ans = 1 / ans;
    printf("%.8f\n",ans);
    return 0;
}