//https://atcoder.jp/contests/abc172/tasks/abc172_c
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m,k;
    unsigned long int t=0;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    for(int i=0;i<m;i++){
        t = t + b[i];
    }
    int j = m;
    int ans = 0;
    for(int i=0;i<n+1;i++){
        while(j > 0 && t > k){
            --j;
            t -= b[j];
        }
        if(t > k){
            break;
        }
        ans = max(ans, i+j);
        if(i==n){
            break;
        }
        t += a[i];
    }
    cout << ans << endl;
}