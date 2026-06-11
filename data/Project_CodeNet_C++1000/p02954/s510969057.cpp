#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> chs(n);

    vector<int> nr;
    rep(i,n-1){
        if(s.at(i) == 'R' && s.at(i+1) == 'L') nr.push_back(i);
    }
    
    for(int x : nr){
    // cout << x << endl;

        chs.at(x) = 1;
        chs.at(x+1) = 1;
        for(int i=x-1;i>=0 && s.at(i) == 'R';i--) {
            // cout << "i:" << i << " x:" << x << endl;
            if((x-i)%2==1) chs.at(x+1)++;
            else chs.at(x)++;
        }
        for(int i=x+2;i<n && s.at(i) == 'L';i++) {
            if((i-x)%2==1) chs.at(x+1)++;
            else chs.at(x)++;
        }
    }
    rep(i,n){
        if(i>0) cout << " ";
        cout << chs.at(i);
    }
    cout << endl;
    return 0;
}