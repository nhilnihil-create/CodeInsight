#include <iostream>

using namespace std;

template <typename T>
void cout_seq(T seq[],int n){
  for(int i=0;i<n;i++){
    if(i){
      cout<<" ";
    }
    cout<<seq[i];
  }
  cout<<endl;
}

int insertion_sort(int A[],int n,int g){
  int cnt = 0;
  for(int i=g;i<n;i++){
    int v = A[i];
    int j = i - g;
    while(j>=0 && A[j]>v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
  return cnt;
}

int shell_sort(int A[],int n){
  int cnt = 0;
  int G[n];
  int v = (n > 1) ? n-1:1;
  int m = 0;
  for(int i=0;;i++){
    G[i] = v;
    if(v==1){ m = i+1; break;}
    v = v / 2;
  }
  cout<<m<<endl;
  cout_seq(G,m);
  for(int i=0;i<m;i++){
    cnt += insertion_sort(A, n, G[i]);
  }
  return cnt;
}

int main() {
  int n; cin>>n;
  int seq[n];
  for(int i=0;i<n;i++) cin>>seq[i];
  int count = 0;
  count = shell_sort(seq,n);
  cout<<count<<endl;
  for(auto a:seq)
  {
    cout<<a<<endl;
  }
}