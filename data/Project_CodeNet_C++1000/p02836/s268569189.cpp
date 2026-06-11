#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;

int main (){
    string s;
    cin >> s ;
    string rev = s;
    reverse(rev.begin(),rev.end());
    int ans = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] != rev[i])ans++;
    }
    cout << ans/2 << endl;
    return 0;
}   