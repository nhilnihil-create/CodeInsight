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
    int n;
    cin >> n;
    string s;
    int cnt =0;
    reps(i,1,n+1){
        s = to_string(i);
        if(s.length() % 2 == 1){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}