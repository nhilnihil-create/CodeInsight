#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    rep(i, N){
        int a;
        cin >> a;
        if(a % 2 == 0){
            if((a % 3 != 0) && (a % 5 != 0)){
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}