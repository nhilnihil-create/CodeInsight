#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define repp(i, n) for (int i = 0; i <=(int)(n); i++)
int main(){
    string s,t;
    cin >> s >> t;
    rep(i,s.length()){
        if(s[i]!=t[i])
            {
                cout << "No" ;
                return 0;
            }
    }

cout << "Yes";
 return 0;

}