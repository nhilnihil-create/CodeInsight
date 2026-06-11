#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    int n;
    cin >> n;
    int tmp;
    map<int,int> mp;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        mp[tmp]++;
    }
 
    vector<int> v(3,0),v2(3,0);
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
