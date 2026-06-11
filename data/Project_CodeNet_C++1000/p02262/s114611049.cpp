#include<iostream>
#include<cmath>
using namespace std;
#include<vector>

#define ArrayNum 1000000

vector<int> g;

int insertionSort(int a[],int n,int g){
  int i,j,cnt=0,v;

  for(i=g;i<n;i++){
    v= a[i];
    j=i-g;
    while(j>=0 && a[j]>v){
      a[j+g]=a[j];
      j=j-g;
      cnt++;
    }
    a[j+g]=v;
  }
  return cnt;
}

void shellSort(int a[], int n){
  int i,cnt=0,m;
  
  for(int h=1;;){
    if(h>n)
      break;
  g.push_back(h);
  h=3*h+1;
  }
  m=g.size();
  for(i=m-1;i>=0;i--)
    cnt=cnt+insertionSort(a,n,g[i]);

  cout << m << "\n";
  for(i=m-1;i>0;i--)
    cout << g[i] << " ";
  cout << g[0] << "\n";
  cout << cnt << "\n";
  for(i=0;i<n;i++)
    cout << a[i] << "\n";

}

int main(void){
  int i,n,a[ArrayNum];
  cin >> n;
  for(i=0;i<n;i++)
    cin >> a[i];
  shellSort(a,n);

}

