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
    ll a[3];
    for(ll i=0;i<3;i++){
        a[i]=0;
    }
    ll k,k1;
    cin>>k>>k1;
    a[k-1]=1;
    a[k1-1]=1;
    for(ll i=0;i<3;i++){
        if(a[i]==0){
            cout<<i+1;
        }
    }
    return 0;
}