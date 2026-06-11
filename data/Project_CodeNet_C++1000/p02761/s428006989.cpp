#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> s(m);
    vector<char> c(m);
    rep(i,m){
        cin >> s[i] >> c[i];
    }

    int cnt = 10;
    reps(i,1,n){
        cnt *= 10;
    }
    string num;
    bool flag = true;
    if(n == 1){
        rep(i,10){
            num = to_string(i);
            flag = true;
//            cout << i << " ";
            rep(j,m){
                if(num[s[j]-1] != c[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << i << endl;
                return 0;
            }
        }
    }else{
        reps(i,cnt/10,cnt){
            num = to_string(i);
            flag = true;
            //cout << i << " ";
            rep(j,m){
                if(num[s[j]-1] != c[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;


    return 0;
}