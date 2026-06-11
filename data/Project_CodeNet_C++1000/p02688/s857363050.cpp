#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<math.h>

#define forn(x,n,s) for(int i = x; i < n; i += s )
#define forr(x,n,s) for(int i = x; i>=n; i -= s)
#define PI 3.14159265358979323846264338327950L

using namespace std;

void go(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
  #endif
} 
long long int mod = 1e9+7;

int main(){
    go(); 

    // code here
    int n,k;cin>>n>>k;
    unordered_set<int> st;
    forn(0,k,1){
        int inp;cin>>inp;
        for(int j = 0; j < inp; j++){
            int inp2;cin>>inp2;
            st.insert(inp2);
        }
    }
    cout<<n - st.size();
}



