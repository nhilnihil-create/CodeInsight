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
    string s; cin >> s;
    int n = s.size();
    deque<char> ans;
    for(int i = 0; i < n; i++) ans.push_back(s[i]);

    int Q; cin >> Q;
    bool head = true;
    for(int i = 0; i < Q; i++){
        int t; cin >> t;
        if(t == 1){
            head ^= 1;
        }
        else{
            int f;
            char c;
            cin >> f >> c;
            if(f == 1){
                if(head == true) ans.push_front(c);
                else ans.push_back(c);
            }
            else{
                if(head == true) ans.push_back(c);
                else ans.push_front(c);
            }
        }
    }
    
    if(head == true){
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
        }
        cout << "\n";
    }
    else{
        for(int i = ans.size()-1; i >= 0; i--){
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}
