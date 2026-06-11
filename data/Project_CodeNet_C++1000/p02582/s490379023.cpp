#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int ans=0;
    cin >> s;
    if(s.at(0)=='R'&&s.at(1)=='R'&&s.at(2)=='R'){
        ans=3;
    }
    else if(s.at(0)=='S'&&s.at(1)=='S'&&s.at(2)=='S'){
        ans=0;
    }
    else if((s.at(0)=='S'&&s.at(1)=='R'&&s.at(2)=='R')||(s.at(0)=='R'&&s.at(1)=='R'&&s.at(2)=='S')){
        ans=2;
    }
    else{
        ans=1;
    }
    cout << ans << endl;
    return 0;
}