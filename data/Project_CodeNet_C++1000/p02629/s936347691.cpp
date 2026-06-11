#include<iostream>
#include<bits/stdc++.h>
#include<climits>

#define forn(x,n,s) for(int i = x; i < n; i += s )
#define forr(x,n,s) for(int i = x; i>=n; i -= s)

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
    long long int n;cin>>n; 
    string sol = "";
    while(n){
        n--;
        char temp = 'a' + (n%26);
        sol = temp + sol;
        n /= 26;
    }
    cout<<sol;
}




