#include <string>
#include <iostream>
using namespace std;

int compare(string s, string t){
    int result = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]) result++;
    }
    return result;
}

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int ans = 2000;
    for(int i = 0; i <= n-m; i++){
        string u = s.substr(i,m);
        if(compare(t,u) < ans) ans = compare(t,u);
    }
    cout << ans << endl;
}