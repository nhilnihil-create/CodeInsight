#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(h[i] >= k) count += 1;
    }

    cout << count << endl;
   return 0;
}