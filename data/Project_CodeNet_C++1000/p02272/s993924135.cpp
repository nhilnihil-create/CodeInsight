#include<iostream>
#define INF 2000000000;
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
int cnt=0;
int main(){
  int n;
  std::cin>>n;
  int A[n];
  for(int i=0;i<n;i++) std::cin>>A[i];
  mergeSort(A,0,n);
  for(int i=0;i<n;i++){
    std::cout<<A[i];
    if(i!=n-1) std::cout<<" ";
  }
  std::cout<<"\n"<<cnt<<"\n";
  return 0;
}
void merge(int *A,int l,int m,int r){
  int n1=m-l,n2=r-m, i, j;
  int L[n1+1];
  int R[n2+1];
  for(i=0;i<n1;i++) L[i]=A[l+i];
  for(i=0;i<n2;i++) R[i]=A[m+i];
  L[n1]=R[n2]=INF;
  i=j=0;
  for(int k=l;k<r;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
      cnt++;
    }
    else{
      A[k]=R[j];
      j=j+1;
      cnt++;
    }
  }
}
void mergeSort(int *A,int l,int r){
  int m;
  if(l+1<r){
    m=(l+r)/2;
    mergeSort(A,l,m);
    mergeSort(A,m,r);
    merge(A,l,m,r);
  }
}