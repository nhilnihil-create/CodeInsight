#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
const int INF = 0x7fffffff;
using lll = long long;
using ull = unsigned long long;
using namespace std;


int n,m,q;
vector<int> a,b,c,d;
int ans;

void dfs(vector<int> A){

  if(A.size() == n+1){

    int ii;
    int val = 0;

    for(ii=0;ii<q;ii++){
      if((A[b[ii]] - A[a[ii]]) == c[ii]){
        val += d[ii];
      }
    }

    //cout << "val:" << val << endl;

    ans = max(ans,val);
    
    //for(ii=1;ii<=n;ii++){
    //  cout << a[ii] ;
    //  
    //}
    

    //cout << endl;
    
    return ;
  }

  A.push_back(A.back());

  while(A.back() <= m){
    dfs(A);
    A.back()++;
  }
  
}

int main(){
  int ii,jj,kk,ll,mm,nn,oo,pp,qq,rr;
  vector<int> ret;



  cin >> n >> m >> q;

  a = b = c = d = vector<int>(q);

  for(ii=0;ii<q;ii++){
    cin >> a[ii] >> b[ii] >> c[ii] >> d[ii];
  }

  ans = -1;
  
  dfs(vector<int>(1,1));

  cout << ans << endl;
  
  //lll cnt = 0;
  //for(ii=1;ii<=m;ii++){
  //  for(jj=ii;jj<=m;jj++){
  //    for(kk=jj;kk<=m;kk++){
  //      cout << "ii:" << ii << "jj:" << jj << "kk:" << kk << endl;
  //      cnt++;
  //    }
  //  }
  //}
  //
  //for(ii=1;ii<=m;ii++){
  //  vector<int> num(n);
  //  for(jj=1;jj<=n;jj++){
  //    num[jj] = ii;
  //    
  //  }
  //}
  //cout << cnt << endl;
  return 0;
}
