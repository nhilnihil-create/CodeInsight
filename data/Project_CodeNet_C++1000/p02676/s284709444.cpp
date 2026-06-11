#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k;
    cin >> k >> s;

    if(s.length()<=k){
    }else{
        s = s.substr(0,k)+"...";
    }

    cout << s << endl;
}