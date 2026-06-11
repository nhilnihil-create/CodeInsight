#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    string s; cin >>s;

    if(s == "RRR") cout <<3 <<endl;
    else if(s == "RRS" || s == "SRR") cout <<2 <<endl;
    else if(s == "RSR" || s == "RSS" || s == "SRS" || s == "SSR") cout <<1 <<endl;
    else cout <<0 <<endl;

    return 0;
}
