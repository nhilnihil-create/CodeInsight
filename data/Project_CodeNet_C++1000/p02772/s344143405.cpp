#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
static const long long INF = 1000000;
using p = pair<int64_t,int64_t>;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i,n){
        int a;
        cin >> a;
        if (a % 2 != 0){
            continue;
        }
        else if (a % 3 == 0){
            continue;
        }
        else if(a % 5 == 0){
            continue;
        }
        else {
            cout << "DENIED" << endl;
            return 0;
        }
    }
    cout << "APPROVED" << endl;

}