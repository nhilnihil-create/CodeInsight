#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define MAX 1000010

using namespace std;

int n,A[MAX],cnt;

void insertionSort(int g){
  REP(i,g,n){
    int v = A[i];
    int j = i - g;
    while( j >= 0 && A[j] > v ){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(){
  cnt = 0;
  /*
  int m = rand() % min(n,100) + 1;
  int *G = new int[m];
  G[0] = 1;
  set<int> used;
  used.insert(1);
  REP(i,1,m){
    int v = rand() % n + 1;
    while( used.find(v) != used.end() ) v = rand() % n + 1;
    used.insert(v);
    G[i] = v;
  }
  sort(G,G+m);
  */
  int m = 1;
  vector<int> G;
  G.push_back(1);
  while( G.back()*3+1 <= n && m < 100 ){
    m++;
    G.push_back(G.back()*3+1);
  }
  reverse(G.begin(),G.end());
  rep(i,m)insertionSort(G[i]);
  cout << m << endl;
  rep(i,m){
    if( i ) cout << ' '; 
    cout << G[i];
  } cout << endl;
  cout << cnt << endl;
  rep(i,n)cout << A[i] << endl;
  //delete [] G;
}

int main(){
  srand((unsigned int)time(NULL));
  cin >> n;
  rep(i,n)cin>>A[i];
  shellSort();
  return 0;
}