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
using pii = pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    string s;
    vector<pii> vec(m);
    rep(i,m){
        int s,c;
        cin >> s >> c;
        vec[i] = make_pair(s,c);
    }
    //cout << pow(10,n-1) << " " << pow(10,n) << endl;
    

    bool flag;
    
    int start = pow(10,n-1);
    if(start == 1) start = 0;

    reps(i,start,pow(10,n)){
        s = to_string(i);
        flag = true;
        rep(j,m){
            if((int)(s[vec[j].first-1]-'0') != (vec[j].second) ){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}