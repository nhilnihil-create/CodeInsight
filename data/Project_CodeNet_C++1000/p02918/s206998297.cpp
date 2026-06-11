#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    char cur = s.at(0);
    vector<int> cnts;
    int cnt = 0;
    rep(i, s.size()){
        if(s.at(i) == cur){
            cnt++;
        }
        else{
            cnts.push_back(cnt);
            cnt = 1;
        }
        cur = s.at(i);
    }
    cnts.push_back(cnt);

    // for(int c:cnts){
    //     cout << c << " ";
    // }
    // cout << endl;

    int hp = 0;
    for(int c : cnts) hp += c-1;
    int kind = cnts.size();
    int opmx = kind/2;
    if(opmx <= k){
        hp += kind-1;
    }else{
        hp += k*2;
    }
    cout << hp << endl;
    return 0;
}