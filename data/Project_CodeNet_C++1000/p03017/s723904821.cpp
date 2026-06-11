#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
    int N,a,b,c,d;
    cin >> N >> a >> b >> c >> d;
    string s;
    cin >> s;
    bool ok=true;
    a--;b--;c--;d--;
    for(int i=a+1;i<c&&i+1<N;i++){
        ok&=!((s[i]=='#')&&(s[i+1]=='#'));
    }
    for(int i=b+1;i<d&&i+1<N;i++){
        ok&=!((s[i]=='#')&&(s[i+1]=='#'));
    }
    if(!ok){cout << "No" << endl;return 0;}
    if(d<c){
        for(int i=b-1;i<d&&i+2<N;i++){
            if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
    else{cout << "Yes" << endl;}


    return 0;
}