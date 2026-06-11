#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define tab " "
#define lli long long int
#define pb push_back

void read(){
    string s;
    lli si;

    cin >> si >> s;

    if(s.size() <= si) cout << s;
    else{
        for(int i = 0; i < si; ++i){
            cout << s[i];
        }
        cout << "..." << endl;
    }

    return;
}

int main(){
    read();
    return 0;
}