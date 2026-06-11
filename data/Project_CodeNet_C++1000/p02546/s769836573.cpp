#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string s;
    cin >> s;
    int len = s.size();

    if(s.at(len-1) == 's'){
        cout << s << "es" << endl;
    }else{
        cout << s << "s" << endl;
    }

}