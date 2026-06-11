#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    string t;
    cin >> t;
    for(long long i;i<t.size();i++){
        if(t.at(i)=='?'){
            cout << 'D';
        }else{
            cout << t.at(i);
        }
    }
    cout << endl;
}