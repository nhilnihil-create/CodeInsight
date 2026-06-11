#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

long long cnt;
vector<int> G;

void InsertionSort(int a[],int n,int step){
  for(int i=step;i<n;i++){
    int temp=a[i],j=i-step;
    while(j>=0 && a[j]>temp){
      a[j+step]=a[j];
      j-=step;
      cnt++;
    }
    a[j+step]=temp;
  }
}

void ShellSort(int a[],int n){
  for(int h=1; ; ){
    if(h>n) break;
    G.push_back(h);
    h=3*h+1;
  }
  for(int i=G.size()-1;i>=0;i--) InsertionSort(a,n,G[i]);
}

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  cnt=0;
  ShellSort(a,n);

  cout << G.size() << endl;
  for(int i=G.size()-1;i>=0;i--){
    printf("%d",G[i]);
    if(i) printf(" ");
  }
  cout << endl;
  cout << cnt << endl;
  for(int i=0;i<n;i++) cout << a[i] << endl;
  return 0;
}