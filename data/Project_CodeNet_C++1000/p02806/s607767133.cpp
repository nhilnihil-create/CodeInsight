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
    int n;
    cin >> n;
    vector<string> vec1(n);
    vector<int> vec2(n);

    rep(i,n){
        cin >> vec1[i] >>  vec2[i]; 
    }
    string str;
    cin >> str;

    bool flag = false;

    int cnt = 0;
    rep(i,n){
        if(flag){
            cnt += vec2[i];
        }
        if(str == vec1[i]) flag = true;
    }

    cout << cnt << endl;
    return 0;
}