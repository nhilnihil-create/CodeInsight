#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main(){
    string s;
    cin >> s;

    if(s[s.size()-1]=='s'){
        s+="es";
    }
    else{
        s+='s';
    }

    cout << s << endl;

    return 0;
}

