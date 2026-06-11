//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
#define sz 4
vector <long long int> vv[sz];
int main(){
    long long int n,i,j,x,y,mx = 0,temp;
    cin >> n;
    for(i = 0;i<n;i++){
        cin >> x >> y;
        vv[0].push_back(x + y);
        vv[1].push_back(x - y);
        vv[2].push_back(-x - y);
        vv[3].push_back(-x + y);
    }
      for(i = 0;i<4;i++) {
          sort(vv[i].begin(),vv[i].end());
          mx = max(mx,vv[i][n-1] - vv[i][0]);
      }
       cout << mx << endl;
    return 0;
}