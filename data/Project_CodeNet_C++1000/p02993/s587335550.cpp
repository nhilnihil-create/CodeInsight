#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s;
    cin >> s;
    int l;
    l=s.size();
    int k=0;
    rep(i,l-1){
        if(s[i]==s[i+1]){
            k=1;
        }
    }

    if(k==1){
        cout << "Bad" << endl;
    }
    else{
         cout << "Good" << endl;
    }
    

    return 0;
}