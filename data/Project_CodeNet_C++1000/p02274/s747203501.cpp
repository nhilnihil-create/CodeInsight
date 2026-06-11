#include<bits/stdc++.h>

using namespace std;
#define fordebug int hoge;cin>>hoge;
#define DEKAI 1000000007;
#define INF 2000000000
#define int long long
#define lp(i,n) for(int i=0;i<n;i++)
#define lps(i,j,n) for(int i=j;i<n;i++)
int ll[200000],rr[200000];
long long cnt=0;	

int merge(int a[],int l, int m,int r){
  int n1=m-l;
  int n2=r-m;
  lp(i,n1) ll[i]=a[l+i];
  lp(i,n2) rr[i]=a[m+i];
  int i=0,j=0;
  ll[n1]=INF;
  rr[n2]=INF;
  lps(k,l,r){
    if(ll[i]<rr[j]){
      a[k]=ll[i];
      i++;
    }
    else{
      a[k]=rr[j];
      j++;
      cnt+=(long long)n1-(long long)i;
    }
  }
  return cnt;
}

int mergesort(int a[],int l,int r){
  if(l+1<r){
    int m=(l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m,r);
    merge(a,l,m,r);
  }
  else return 0;
}

signed main(){
  int n;
  cin>>n;
  int a[200000];
  lp(i,n){
    cin>>a[i];
  }
  mergesort(a,0,n);
  cout<<cnt<<endl;
  return 0;
}


