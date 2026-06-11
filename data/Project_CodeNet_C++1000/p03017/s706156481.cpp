#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,a,b,c,d;
string s;

int main(){
    cin >> n >> a >> b >> c >> d;
    cin >> s;
    a--;
    b--;
    c--;
    d--;
    bool flags=true;
    for(ll i=a;i<c;i++){
        if(s[i]=='#'&&s[i+1]=='#') flags=false;
    }
    bool flagf=true;
    for(ll i=b;i<d;i++){
        if(s[i]=='#'&&s[i+1]=='#') flagf=false;
    }
    if(!flags||!flagf){
        cout << "No" << endl;
        return 0;
    }
    bool flag=false;
    if(c<d) flag=true;
    else{
        for(ll i=b;i<=d;i++){
            if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.') flag=true;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}  
