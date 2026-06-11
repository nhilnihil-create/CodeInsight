#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;

string group(string s){
    string result;
    result += s[0];
    for(int i(0); i<s.length() - 1; i++){
        if(s[i] != s[i+1]){
            result += s[i+1];
        }
    }
    return result;
}

int main(){
    io

    int n;
    string s;
    cin >> n >> s;

    string str;
    str = group(s);
    
    cout << str.length() << endl;

    return 0;
}