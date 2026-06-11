#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        mp[a]++;
    }

    if(n%3){
        if(mp.count(0) && mp[0] == n)cout << "Yes";
        else cout << "No";
    }else{
        if(mp.size() > 3)cout << "No";
        else if(mp.count(0) && mp[0] == n)cout << "Yes";
        else{
            vector<int> non_zeros;
            for(auto e: mp){
                if(e.first == 0)continue;
                non_zeros.push_back(e.first);
            }
            if(non_zeros.size() == 1){
                if(mp[non_zeros[0]] == n/3*2)cout << "Yes";
                else cout << "No";
            }else if(non_zeros.size() == 2){
                cout << "No";
            }else{
                if((non_zeros[0]^non_zeros[1]^non_zeros[2]) == 0 && mp[non_zeros[0]] == n/3 && mp[non_zeros[1]] == n/3)
                    cout << "Yes";
                else cout << "No";
            }
        }
    }
    cout << endl;

    return 0;
}