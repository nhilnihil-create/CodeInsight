#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for(int i=0; i<n; ++i){
        cin >> a[i];
        s += a[i];
    }

    int p1 = (float)s/n;
    int p2 = (float)s/n + 1;

    int ans1=0, ans2=0;
    for(int i=0; i<n; ++i){
        ans1 += (a[i]-p1) * (a[i]-p1);
        ans2 += (a[i]-p2) * (a[i]-p2);
    }
    cout << min(ans1, ans2);

    return 0;
}
