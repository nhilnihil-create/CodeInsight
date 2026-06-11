#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double 
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ld a,v;
    ld b,w;
    ld t;
    cin>>a>>v>>b>>w>>t;
    if(b > a){
    if(v <= w){
        cout<<"NO\n";
    }else{
        if((b-a)/(v-w) <= t){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    }else if(a > b){
        if(v <= w){
            cout<<"NO\n";
        }else{
            if((a-b)/(v-w) <= t){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        } 
    }
}