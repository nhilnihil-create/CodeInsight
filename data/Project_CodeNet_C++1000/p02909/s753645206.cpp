#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    string s;
    cin >> s;
    
    if(s == "Sunny")
        cout << "Cloudy" << endl;
    else if(s == "Cloudy")
        cout << "Rainy" << endl;
    else
        cout << "Sunny" << endl;
    
    
    
    return 0;
}
