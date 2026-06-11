#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int n;
    cin >>n;
    vector<int> a(n);
    
    for(int x = 1;x <= sqrt(n);x++){
        for(int y = 1;y <= sqrt(n);y++){
            for(int z = 1;z <= sqrt(n);z++){
                int value = x*x + y*y + z*z + z*x + z*y + x*y;
                if(value <= n) a[value]++;
            }
        }
    }

    for(int i = 1;i<=n;i++) cout << a[i] << endl;
}