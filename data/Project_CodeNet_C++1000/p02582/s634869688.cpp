#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descsort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void)
{
    string s;
    cin>>s;
    bool p=s[0]=='R';
    bool q=s[1]=='R';
    bool r=s[2]=='R';
    if(p && q && r)cout<<3<<endl;
    else if((p && q)||(q&&r))cout<<2<<endl;
    else if(p||q||r)cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}