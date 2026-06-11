#include <bits/stdc++.h>
using namespace std;

int N,n;string A;int* B;
unsigned long long b1=100000007LL;unsigned long long* base;unsigned long long b2=1000000007LL;

void init(unsigned long long b) {
  base[0]=1LL;
  for (int i=0;i<n;i++) {
    base[i+1]=base[i]*b;
  }
}

int rollinghash(int a,int b,int b1) {
  unsigned long long start=0LL;
  for (int i=0;i<b;i++) {
    start+=base[b-1-i]*B[i+a];
  }
  unsigned long long x=start;int r=0;
  for (int i=0;i<N-a-b;i++) {
    x=x*b1-base[b-1]*b1*B[i+a]+B[i+a+b];
    if (i>=b-1 && x==start) {
      r=b;
      break;
    }
  }
  return r;
}

int main() {
  cin >> N >> A;B=new int[N];n=N/2;base=new unsigned long long[n+1];
  for (int i=0;i<N;i++) {
    B[i]=A.at(i)-'a';
  }
  init(b1);
  int right=n;int left=0;int mid;
  while (right!=left) {
    mid=(right+left+1)/2;
    bool x=false;
    for (int i=0;i<N-mid+1;i++) {
      if (rollinghash(i,mid,b1)>0) {
        x=true;
        break;
      }
    }
    if (x) left=mid;
    else right=mid-1;
  }
  init(b2);
  int right2=n;int left2=0;int mid2;
  while (right2!=left2) {
    mid2=(right2+left2+1)/2;
    bool x2=false;
    for (int i=0;i<N-mid2+1;i++) {
      if (rollinghash(i,mid2,b2)>0) {
        x2=true;
        break;
      }
    }
    if (x2) left2=mid2;
    else right2=mid2-1;
  }
  cout << max(left,left2) << endl;
}