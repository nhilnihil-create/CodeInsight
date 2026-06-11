#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s,t;
    cin >> s >> t;

    int last = t.length();
    for(int x=0;x<=(s.length()-t.length());x++){
        int min = 0;
        for(int y=0;y<t.length();y++){
            if(s[x+y]!=t[y])min++;
        }
        //cout << min << endl;
        if(min<last){
            last = min;
        }
    }
    cout << last << endl;
}