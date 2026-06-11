#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define tinput int t; cin>>t; while(t--)
#define rep(i,n,s) for((i)=(s); (i)<(n); (i)++)

template <typename T>
T mini(T x, T y) { return (x<y)?x:y; }
template <typename T>
T maxi(T x, T y) { return (x>y)?x:y; }

int main(){
  //  freopen("input2.txt", "r", stdin);
  //  freopen("output2.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int d, t, s;
    cin>>d>>t>>s;

    int x=d/s;
    if(d%s!=0)
        x++;
    if(t>=x) cout<<"Yes";
    else cout<<"No";
   
    return 0;
}