#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl

int main(){
    string s;
    cin >> s;
    string cmp = "";
    for(int i = 0; i < 5; i++){
        cmp += "hi";
        if(s == cmp){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;

}
