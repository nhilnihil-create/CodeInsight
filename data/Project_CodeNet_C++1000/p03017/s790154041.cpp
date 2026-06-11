#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<utility>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> Pi;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}


int main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;

    s = '#' + s + '#';

    auto reachable = [&](int start, int end){
        for (int i = start; i + 1 <= end; i++) {
            if (s[i] == '#' && s[i + 1] == '#') return false;
        }
        return true;
    };

    if(!reachable(a, c) || !reachable(b, d)){
        cout << "No" << endl;
        return 0;
    }

    if(c > d){
        bool snuke_over = false;
        for(int i = b; i <= d; i++){
            if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
                snuke_over = true;
            }
        }
        if(!snuke_over){
            cout << "No" << endl;
            return 0;
        }
    }


    cout << "Yes" << endl;
    return 0;
}
