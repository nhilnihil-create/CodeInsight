#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    s = "#" + s + "#";

    reps(i,a,c){
        if(s[i] == '#' && s[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }
    reps(i,b,d){
        if(s[i] == '#' && s[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }

    if(c < d){
        cout << "Yes" << endl;
        return 0;
    }else{
        reps(i,b,d+1){
            if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}

