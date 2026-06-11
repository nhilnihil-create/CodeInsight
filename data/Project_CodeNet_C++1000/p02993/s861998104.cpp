#include <iostream>
#include <iomanip>
#include <string>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    string s;
    cin >> s;
    repi(i,s.size(),1){
        if(s[i] == s[i - 1]){
            cout << "Bad" << endl;
            return 0;
        }
    }
    cout << "Good" << endl;
    return 0;
}