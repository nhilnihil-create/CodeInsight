//

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define nnn "\n"
const int inf = 2147483647;

int main (){
    string a;cin>>a;
    if(stoi(a)<100){cout << "0" << nnn;return 0;}
    int r = a.size();
    int s = stoi(a.substr(r-2,2));
    int d = stoi(a.substr(0,r-2));
    if(d*5>=s)cout << "1" << nnn;
    else cout << "0" << nnn;
    return 0; 
}