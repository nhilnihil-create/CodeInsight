#include<iostream>
#include <vector>
using namespace std;
     
int Merge(int A[],int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int i,j,k;
  int L[n1+1],R[n2+1];
       
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=1000000000;
  R[n2]=1000000000;
       
  i=j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
      j++;
    }
  }
  return right-left;
}
     
int Merge_Sort(int A[],int left,int right){
  int mid,res=0;
  if(left+1<right){
    mid=(left+right)/2;
     
    res+=Merge_Sort(A,left,mid);
    res+=Merge_Sort(A,mid,right);
    res+=Merge(A,left,mid,right);
         
  }
  return res;
}
  
int merge(vector<int> &vec, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
  
    vector<int> l(n1);
    for (int i = 0; i < n1; ++i) l[i] = vec[left + i];
  
    vector<int> r(n2);
    for (int i = 0; i < n2; ++i) r[i] = vec[mid + i];
  
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) vec[k++] = l[i++];
        else              vec[k++] = r[j++];
    }
    while (i < n1) vec[k++] = l[i++];
    while (j < n2) vec[k++] = r[j++];
  
    return right - left;
}
  
int MergeSort(vector<int> &vec, int left, int right) {
    int res = 0;
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        res += MergeSort(vec, left, mid);
        res += MergeSort(vec, mid, right);
        res += merge(vec, left, mid, right);
    }
  
    return res;
}
  
int main(){
  int i,x,n,S[500000]; 
  cin>>n;
  for(i=0;i<n;i++)cin>>S[i];
  
  vector<int> vec(S,S + n);
  MergeSort(vec, 0, vec.size());
     
  x=Merge_Sort(S,0,n);
       
  for(i=0;i<n;i++){
    if(i)cout<<" ";
    cout<<vec[i];
  }
  cout<<endl;
  cout<<x<<endl;
  return 0;
}
