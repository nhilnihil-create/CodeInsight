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
    ll a[y];
    f(i,y){
        cin>>a[i];
    }
    ll ans=0;
    ll k=1;
    for(ll i=0;i<y;i++){
        if(a[i]==k){
            k++;
        }
        else{
            ans++;
        }
    }
    if(ans==y){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
    return 0;
}