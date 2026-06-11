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
    if(s.size()%2==1){cout<<"No"<<endl;return 0;}
    bool ok=true;
    rep(i,0,s.size()){
        if(i%2){
            if(s[i]!='i'){ok=false;break;}
        }else{
            if(s[i]!='h'){ok=false;break;}
        }
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}