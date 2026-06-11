#include<bits/stdc++.h>
#define ll long long 
#define P pair<ll ,ll>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    int r,s,p;
    cin >> r >> s >> p;
    string t;
    cin >> t;

    ll ans = 0;
    vector<char>was(n ,'x');
    for(int i=0;i<n;i++){
        if(i-k >=0){
            if(was[i-k]!='r' && t[i]=='r'){
                ans += p;
                was[i] = 'r';
            }
            if(was[i-k]!='s' && t[i]=='s'){
                ans += r;
                was[i] = 's';
            }
            if(was[i-k]!='p' && t[i]=='p'){
                ans += s;
                was[i] = 'p';
            }
        }else{
            if( t[i]=='r'){
                ans += p;
                was[i] = 'r';
            }
            if( t[i]=='s'){
                ans += r;
                was[i] = 's';
            }
            if( t[i]=='p'){
                ans += s;
                was[i] = 'p';
            }
        }
    }

    cout << ans << endl;
}