
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int aa, ab, ac;
    cin >> aa >> ab >> ac;
    if(aa+ab+ac>=22){
        cout << "bust" << endl;
        return 0;
    }
    else{
        cout << "win" << endl;
        return 0;
    }
}