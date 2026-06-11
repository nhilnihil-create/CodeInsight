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
    repi(i,s.size(),0){
    int a = 0;
        repi(j,s.size(),0){
            if(s[i] == s[j])a++;
        }
        if(a != 2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}