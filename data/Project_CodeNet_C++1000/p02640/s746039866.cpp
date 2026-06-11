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
    int x,y;cin>>x>>y;
    forn(0,x+1,1){
        int b = x - i;
        if((2*i + 4*b)==y){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}




