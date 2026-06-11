#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <set>

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
    int tmp;
    map<int,int> mp;
    rep(i,n){
        cin >> tmp;
        mp[tmp]++;
    }

    vi v(3,0),v2(3,0);
    int i = 0;
    int size = mp.size();
    if(size == 3){
        for(auto e : mp){
            v[i] = e.first;
            v2[i] = e.second;
            i++;
        }
    }

    if(mp[0] == n){
        cout << "Yes" << endl;
        return 0;
    }else if(mp[0] * 3 == n && size == 2){
        cout << "Yes" << endl;
        return 0;
    }else if(size == 3){
        if((v2[0] == v2[1] && v2[1] == v2[2]) && ((v[0] ^ v[1]) ^ v[2]) == 0)  {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
