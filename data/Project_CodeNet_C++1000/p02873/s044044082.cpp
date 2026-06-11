#include <iostream>
#include <vector>
using namespace std;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
int main(){
    string s; 
    cin >> s;
    vector<long long> a(s.size()+1);
    for(int i=0; i<s.size(); i++){
        if (s[i] == '<'){
            chmax(a[i+1], a[i]+1);
        }
    }
    for(int i = s.size()-1; i >= 0; i--){
        if (s[i] == '>'){
            chmax(a[i], a[i+1]+1);
        }
    }
    long long ans = 0;
    for(int i=0; i<s.size()+1; i++) ans += a[i];
    cout << ans << endl;
    return 0;
}