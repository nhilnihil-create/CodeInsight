#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n=s.size();
    vector<int> a(n+1);
    a[0]=0;
    int p=1;
    for(int i=0; i<n; i++){
        int x = s.at(n-i-1)-'0';
        a[i+1] = (a[i]+x*p)%2019;
        p *= 10;
        p %= 2019;
    }
    sort(a.begin(),a.end());
    long long ans =0;
    long long t=0;
    for(int i=0; i<n; i++){
        if(a[i] == a[i+1]){
            t++;
        } else {
            t=0;
        }
        ans += t;
    }
    cout << ans << endl;
 
}