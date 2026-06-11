#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  vector<vector<int>> k(n,vector<int>(1,-1));
  int a[n];
  int b[n];
  int z[n];
  z[0]=0;
  rep(i,n-1){
    int c,d;
    cin >> c >> d;
    c--;
    d--;
    a[i]=c;
    b[i]=d;
    k[c].push_back(d);
    k[d].push_back(c);
  }  
    int c[n];
    c[0]=0;
    rep(i,n-1)c[i+1]=-1;
    int ma=(k[0].size()-1);
    rep(i,n){
      int ww=(k[i].size()-1);
      ma=max(ma,ww);
    }
    cout << ma << endl;
    queue<int> q;
    q.push(0);
    int oo=1;
    while(q.size()!=0){
      int y=q.front();
      z[y]=oo;
      oo++;
      q.pop();
      int cc=1;
      int pp=1;
      for(int u:k[y]){
        if(u==-1)continue;
        if(c[u]!=-1){
          pp++;
          continue;
        }
        if(cc==c[y])cc++;
        c[u]=cc;
        q.push(u);
        cc++;
      }
    }
  rep(i,n-1){
    int aa=a[i];
    int bb=b[i];
    if(z[aa]>z[bb])cout << c[aa] << endl;
    else cout << c[bb] << endl;
  }
}
