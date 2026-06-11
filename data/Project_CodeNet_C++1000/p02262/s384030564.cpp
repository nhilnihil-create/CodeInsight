#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long cnt;
int l;
int A[10000000];
int n;
vector<int> G;

void insert(int A[],int n,int g){
  int i,j,v;
  for(i=g;i<n;i++){
    v=A[i];
    j=i-g;
    while(j>=0 && A[j]>v){
      A[j+g]=A[j];
      j=j-g;
      cnt++;
    }
      A[j+g]=v;
  }
}

void shellsort(int A[],int n){
  int i,j;
  for(i=1;;){
    if(i>n)break;
    G.push_back(i);
    i=3*i+1;
  }
  for(j=G.size()-1;j>=0;j--){
    insert(A,n,G[j]);
  }
}
int main(){
  int i,j;

  cin >> n;
  for(i=0;i<n;i++){
    cin >> A[i];
  }
  cnt=0;
  
  shellsort(A,n);

  cout<<G.size()<<endl;
  for(i=G.size()-1;i>=0;i--){
    cout << G[i];
    if(i){
    cout << " ";
    }
  }
  cout << endl;
  cout << cnt<<endl;

  for(i=0;i<n;i++){
    cout << A[i]<< endl;
  }
}