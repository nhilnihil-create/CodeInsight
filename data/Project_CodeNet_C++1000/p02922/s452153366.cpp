// 15:20-15:25
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int A, B;
    cin >> A >> B;

    int cnt = 0;
    while(1 + (A - 1) * cnt < B){
        cnt++;
    }
    
    cout << cnt << endl;

    return 0;
}