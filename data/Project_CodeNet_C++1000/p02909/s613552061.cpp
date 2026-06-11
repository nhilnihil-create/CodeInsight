#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

int main(){
    string s; cin >> s;
    if(s[0]=='S') cout << "Cloudy" << endl;
    else if(s[0]=='C') cout << "Rainy" << endl;
    else cout << "Sunny" << endl;
}