#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    vector<pair<int,int>> p;
    for(int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        p.push_back(make_pair(x+y,x-y));
    }
      
    sort(p.begin(),p.end());

    int ans=n,memo=p[0].first;
    for(int i=1;i<n;i++){
      if(p[i].second<memo) ans--;
      else memo=p[i].first;
    }
    cout<<ans<<endl;
}