#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
const int Max = 1000000;
void update(vector<int> &a,int x){
  for(int i = x;i<Max;i++){
    a[i] = min(a[i-x]+1,a[i]);
  }
}
    

int main(){
  vector<int> a(Max,Max);
  vector<int> o(Max,Max);
  a[0]=0;o[0]=0;
  for(int i=0;;i++){
    int x=i*(i+1)*(i+2)/6;
    if(x>Max)break;
    update(a,x);
    if(x&1)update(o,x);
  }
  int n;
  while(cin>>n,n){
    cout << a[n] << " " << o[n] << endl;
  }
    return 0;
}