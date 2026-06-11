#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const int MAX = 1e5+10;
const int  MAX1 = 1e5+10;
const int INF = 1e9+10;
double eps = 1e-6;
int main(){
    IOS
    string s, t;
    cin >> s >> t;

    int ln = s.length(), sum = 0;
    for(int i = 0;i < ln;i++){
        if(s[i] != t[i]){
            sum++;
        }
    }
    cout << sum << endl;


}


/*


*/
