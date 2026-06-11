#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> cnt(n + 1, 0);
    int now = - 1;
    int tmp = 0;
    for (int i = 0; i < n; i++){
        if (a[i] != now){
            now = a[i];
            tmp = 1;
        }
        else tmp++;
        cnt[tmp]++;
    }
    vector<int> acc(n + 1, 0);
    for (int i = 1; i <= n; i++) acc[i] = acc[i - 1] + cnt[i];
    int ok = n;
    for (int i = 1; i <= n; i++){
        while(acc[ok] < (long long)ok * i) ok--;
        cout << ok << endl;
    }
}
