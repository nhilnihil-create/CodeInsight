
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    int high=0;
    for(int i=0; i<n; i++){
        int h;
        cin >> h;
        if(high - 2 >= h){
            cout << "No" << endl;
            return 0;
        }
        high = max(high,h);
    }
    cout << "Yes" << endl;
    return 0;


}