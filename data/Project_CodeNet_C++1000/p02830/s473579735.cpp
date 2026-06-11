//Try until you reach your goal
#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define endl "\n"
# define str string
# define vll vector<ll>
# define pb push_back
# define mll map<ll,ll>
# define mp make_pair
# define ff first
# define ss second
# define pll pair<ll,ll>
# define f(x,y) for(int x=0;x<y;x++)
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll y;
    cin>>y;
    str s,s1;
    cin>>s>>s1;
    for(ll i=0;i<s.length();i++){
        cout<<s[i]<<s1[i];
    }
    return 0;
}