#include <bits/stdc++.h>
using namespace std;

int gcd_func(int a, int b){
    return b? gcd_func(b, a%b) : a;
} 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s, t; cin >> s;
    cin >> t;
    int ns = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i]!=t[i])
            ns++;
    }
    cout << ns;
    return 0;
}