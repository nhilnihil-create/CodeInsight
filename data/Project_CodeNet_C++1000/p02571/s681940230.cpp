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
 //   freopen("output2.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s, t;
    cin>>s>>t;
    int ans = 1000;
    for(int i=0;i<=(s.length()-t.length());i++) {
        int aux=0;
        for(int j=0;j<t.length();j++) {
            if(s[i+j]!=t[j]) aux++;
        }
        if(aux<ans) ans=aux;
    }
    cout<<ans;
   
    return 0;
}