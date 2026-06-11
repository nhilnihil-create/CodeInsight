#include<bits/stdc++.h>
#define MAX 200000
#define rep(i, n) for(int i=0; i<n; i++)
typedef unsigned int ui;
typedef unsigned long long ull;

using namespace std;

int n, b;
ull cnt=0;
ui A[MAX],B[MAX];
priority_queue<pair<int, int> > S;

/*
void prnt(multiset<pair<int, int> > S){
  cout << S.size() << endl;
  for(multiset<pair<int, int> >::iterator it=S.begin(); it!=S.end(); it++){
    cout << " " << it->first;
  }
  cout << endl;
}
*/

int main(){
  scanf("%d", &n);
  rep(i, n) scanf("%ud", &A[i]);
  rep(i, n){
    scanf("%ud", &b);
    B[i]=b;
    if(A[i]<b){
      S.push(make_pair(b, i));
    } else if(A[i]>b){
      puts("-1");
      return 0;
    }
  }
  while(S.size()!=0){
    pair<int, int> mx=S.top();
    S.pop();
    int i=mx.second;
    int im=i-1, ip=i+1;
    if(im==-1)im=n-1;
    if(ip==n)ip=0;
    ui x=(B[im]+B[ip]);
    ui y=max(B[im], B[ip]);
    ui cntp=min((B[i]-A[i])/x, (B[i]-y)/x+1);
    if(cntp==0){
      puts("-1");
      return 0;
    }
    cnt+=cntp;
    B[i]-=cntp*x;
    if(B[i]>A[i]){
      S.push(make_pair(B[i], i));
    }

  }

  printf("%lld\n", cnt);
  return 0;
}
