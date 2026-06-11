#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int A[3][3];
  for(int i=0;i<3;++i) {
    for(int j=0;j<3;++j) {
      cin>>A[i][j];
    }
  }
  int N;
  cin>>N;
  int tmp;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    for(int j=0;j<3;++j) {
      for(int k=0;k<3;++k) {
        if(A[j][k]==tmp) A[j][k] = -1;
      }
    }
  }
  bool can = false;
  if(A[0][0]==A[0][1] && A[0][1]==A[0][2]) can = true;
  if(A[1][0]==A[1][1] && A[1][1]==A[1][2]) can = true;
  if(A[2][0]==A[2][1] && A[2][1]==A[2][2]) can = true;
  if(A[0][0]==A[1][0] && A[1][0]==A[2][0]) can = true;
  if(A[0][1]==A[1][1] && A[1][1]==A[2][1]) can = true;
  if(A[0][2]==A[1][2] && A[1][2]==A[2][2]) can = true;
  if(A[0][0]==A[1][1] && A[1][1]==A[2][2]) can = true;
  if(A[2][0]==A[1][1] && A[1][1]==A[0][2]) can = true;
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

