#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            sum += d[i]*d[j];
        }
    }

    cout << sum << endl;
   return 0;
}