#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<string>
#include<cassert>
#include<numeric>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    string s;   cin >> s;
    int Q;  cin >> Q;
    int p = 0;
    for(int i=0; i<Q; i++){
        int t;  cin >> t;
        if(t == 1) p++;
        else{
            int f;  string c;   cin >> f >> c;
            if(f == 1){
                if(p%2 == 0)    s = c + s;
                else    s += c;
            }else{
                if(p%2 == 0)    s += c;
                else    s = c + s;
            }
        }
    }
    if(p%2 == 1)    reverse(all(s));
    print(s);
}