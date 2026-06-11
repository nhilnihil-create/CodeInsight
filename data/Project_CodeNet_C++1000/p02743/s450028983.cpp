#include <bits/stdc++.h>
#define rep(n) for(int i=0;i<n;i++)
#define reps(i,s,n) for(int i=s;i<n;i++)
#define rep_bit(n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ll long long
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
using namespace std;
typedef vector<vector<int> > Graph;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;



int main(){

    ll a,b,c;
    cin >> a >> b >> c;

    if(c-a-b>0 && 4*a*b < (c-a-b)*(c-a-b)) CYES;
    else CNO;

    return 0;
}
