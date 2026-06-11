#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>
#include <deque>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    
    int f,t;
    char c;
    
    bool flag = true;

    rep(i,q){
        cin >> f;
        if(f == 1){
            flag = !flag;
        }else{
            cin >> t >> c;
            if(t == 1){
                if(flag){
                    s = c + s;
                }else{
                    s += c;
                }
            }else{
                if(flag){
                    s += c;
                }else{
                    s = c + s;
                }
            }
        }
    }


    if(flag) cout << s << endl;
    else {
        reverse(s.begin(),s.end());
        cout << s << endl;
    }
    
    return 0;
}