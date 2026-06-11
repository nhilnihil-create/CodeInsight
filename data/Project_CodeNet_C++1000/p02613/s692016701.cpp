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
    int n;cin>>n;
    string arr[n];
    forn(0,n,1) cin>>arr[i];
    unordered_map<string,int> mp;
    forn(0,n,1) mp[arr[i]]++;
    cout<<"AC x "<<mp["AC"]<<endl;
    cout<<"WA x "<<mp["WA"]<<endl;
    cout<<"TLE x "<<mp["TLE"]<<endl;
    cout<<"RE x "<<mp["RE"]<<endl;
}




