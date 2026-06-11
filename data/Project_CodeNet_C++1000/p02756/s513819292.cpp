#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define F first
#define S second
#define def(x) cerr << #x << " is " << x << endl;
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(ll i=a;i<n;i++)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(a) a.begin(),a.end()
const int NUM = 2e5 + 5;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

int main(){
    ios
    int num_tests=1; 
    //cin>>num_tests;
    while(num_tests-->0){
        string s; cin>>s;
        int q; cin>>q;
        bool cur = false;
        string front,back;
        while(q--){
            int t; cin >> t;
            if(t==1) cur = !cur;
            else{
                int where; cin >> where;
                char what; cin >> what;
                if(where==1 && !cur || where==2 && cur){
                    front.pb(what);
                }
                else back.pb(what);
            }
        }
        if(cur){
            reverse(all(back));
            cout<<back;
            reverse(all(s));
            cout<<s;
            cout<<front;
        }
        else{
            reverse(all(front));
            cout<<front<<s<<back;

        }
    }   
}
