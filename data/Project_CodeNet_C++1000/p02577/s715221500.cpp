#include <bits/stdc++.h>

using namespace std;
int main(){
    int tol=0;
    string s;
    cin >>s;
    for(auto i:s)tol+=i-'0';
    if(tol%9)cout << "No" <<endl;
    else cout << "Yes" << endl;
}
