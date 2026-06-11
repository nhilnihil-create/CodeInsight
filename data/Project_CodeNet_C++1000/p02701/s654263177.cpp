#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<math.h>

#define forn(x,n,s) for(int i = x; i < n; i += s )
#define forr(x,n,s) for(int i = x; i>=n; i -= s)
#define PI 3.14159265358979323846264338327950L
#define MOD 1e9+7

using namespace std;

void go(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
  #endif
} 

int main(){
    go(); 

    // code here
    int n;cin>>n;
    set<string> st;
    forn(0,n,1){
        string inp;cin>>inp;
        st.insert(inp);
    }
    cout<<st.size();
} 

