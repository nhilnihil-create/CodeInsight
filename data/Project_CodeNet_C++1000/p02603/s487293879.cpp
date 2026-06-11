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

    int n;
    cin>>n;
    ll a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    ll mn = 0;
    ll mx = 0;
    ll money = 1000;
    int i = 0;
    while(i < n - 1){
        if(a[i] <= a[i + 1]){
        mn = a[i];
        while(i < n - 1 && a[i] <= a[i + 1]){
            i++;
        }
        mx = a[i];
        ll stocks = money/mn;
        money -= stocks*mn;
        money += stocks*mx;
        }else{
            i++;
        }
    }
    cout<<money;
}
