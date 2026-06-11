#include <bits/stdc++.h>
using namespace std;

void debug(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

}

  int main() {
    debug();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    int a[n];
    set<pair<int,int>> st;
    for(int i=0; i<n; i++){
    	cin>>a[i];
    	st.insert(make_pair(a[i],i+1));
    }

    for(auto i:st){
    	cout<<i.second<<" ";
    }

    return 0;
  }