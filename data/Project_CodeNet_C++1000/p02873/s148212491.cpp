#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size()+1;
    vector<int> from_left(n),from_right(n);
    rep(i,n-1){
        if(s.at(i) == '>') from_left.at(i+1) = 0;
        else from_left.at(i+1) = from_left.at(i)+1;
    }

    reverse(s.begin(),s.end());
    rep(i,n-1){
        if(s.at(i) == '<') from_right.at(i+1) = 0;
        else from_right.at(i+1) = from_right.at(i)+1;
    }
    reverse(from_right.begin(),from_right.end());
    ll tot=0;
    rep(i,n){
        tot += max(from_right.at(i),from_left.at(i));
    }
    cout << tot << endl;
    return 0;
}