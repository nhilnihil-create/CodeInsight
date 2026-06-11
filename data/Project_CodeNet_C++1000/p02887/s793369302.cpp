#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;

int main(){
    io

    int n;
    string s;
    cin >> n >> s;

    int cont(1);
    char last = s[0];
    for(int i(0); i<s.length(); i++){
        if(s[i] != last){
            cont++;
            last = s[i];
        }
    }
    
    cout << cont << endl;

    return 0;
}