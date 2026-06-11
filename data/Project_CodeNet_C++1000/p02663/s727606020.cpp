#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1,h2,m1,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    h1*=60;
    h1+=m1;
    h2*=60;
    h2+=m2;
    int ans = (h2-h1)-k;
    cout<<ans;
}