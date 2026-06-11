#include <iostream>

using namespace std;

int cnt=0;

void insertionSort(int a[],int n,int g){
  for(int i=g;i<=n-1;i++){
    int v=a[i];
    int j=i-g;
    while(j>=0&&a[j]>v){
      a[j+g]=a[j];
      j=j-g;
      cnt++;
    }
    a[j+g]=v;
  }
}
void reverse(int a[],int n){
  for(int i=0;i<n/2;i++){
    int t=a[i];
    a[i]=a[n-i-1];
    a[n-i-1]=t;
  }
}
int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++)
    cin >> a[i];
  int g[1000];
  g[0]=1;
  int i=0;
  while(g[i]<=n){
    g[i+1]=3*g[i]+1;
    i++;
  }
  int m=i;
  reverse(g,m);
  for(int i=0;i<m;i++)
    insertionSort(a,n,g[i]);
  cout << m << '\n';
  for(int i=0;i<m;i++){
    if(i) cout << " " << g[i];
    else cout << g[i];
  }
  cout << '\n';
  cout << cnt <<'\n';
  for(int i=0;i<n;i++)
    cout << a[i] << '\n';
}