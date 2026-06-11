#include<bits/stdc++.h>

using namespace std;
using ll = long long;

/***********debug tools***********/
template<class T> inline ostream& operator<<(ostream& os,vector<T> arr) {os << "["; for(int i = 0; i < (int)arr.size(); i++)os << arr[i] << (i == (int)arr.size() - 1 ? "]" : ",");os << endl;return os;}
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A,B>& p){os << "{" << p.first << "," << p.second << "}";return os; }
#define prvec(v) cerr<<#v<<": [";for(int __i = 0;__i < (int)(v).size(); __i++)cerr<<((v)[__i])<<(__i+1==(int)(v).size()?"]\n":",");
#define print(x) cerr<<#x<<": "<<(x)<<endl
/*********************************/

int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (ll)(i + 1) * (n - i);
    }

    
    for(int i = 0; i < n - 1; i++) {
        ll a, b; cin >> a >> b; a--, b--;
        if(a > b)swap(a,b);
        ll cur = (a + 1) * (n - b);
        sum -= cur;
    }
    cout << sum << endl;

}