#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;

int main(void){
    // Your code here!
    string s1, s2;
    cin >> s1 >> s2;
    s2.pop_back();
    if(s1 == s2){
        cout << "Yes" << endl;
    }
    else{cout << "No" << endl;}
    return 0;
}
