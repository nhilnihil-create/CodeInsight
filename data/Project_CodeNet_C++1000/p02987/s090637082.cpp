#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    string str;
    bool flag=false;
    cin >> str;
    sort(str.begin(),str.end());
    if(str.at(0)==str.at(1)){
        if(str.at(2)==str.at(3)){
            if(str.at(1)!=str.at(2)){
                flag=true;
            }
        }
    }
    if(flag) cout << "Yes" <<endl;
    else cout <<"No" << endl;
    return 0;
}
