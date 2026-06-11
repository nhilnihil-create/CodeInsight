#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int MX = 1000000001;

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> count(n);
    for(int i=0;i<=n-2;i++){
        for(int j = i+1;j <= n-1;j++){
            count[min(min(abs(i-j),abs(x-1-i)+1+abs(y-1-j)),abs(y-1-i)+1+abs(x-1-j))]++;
        }
    }

    rep(i,n-1)cout << count[i+1] << endl;
}
