#include<iostream>
using namespace std;
int n;
int L[250000],R[250000];
 long long merge(int A[],int left,int mid,int right){
    int n1=mid-left,n2=right-mid;
    long long cnt=0;
     for(int i=0;i<n1;i++)L[i]= A[left+i];
     for(int i=0;i<n2;i++)R[i]=A[mid+i];
     L[n1]=R[n2]=2000000000;
     int i=0,j=0;
     for(int k=left;k<right;k++){
         if(L[i]<=R[j]){
             A[k]=L[i++];
         }
         else{
             A[k]=R[j++];
             cnt+=n1-i;
         }
     }
     return cnt;
}
long long mergeSort(int A[],int left,int right){
    long long t1,t2,t3;
    int mid;
    if(left+1<right){
        mid=(left+right)/2;
        t1=mergeSort(A,left,mid);
        t2=mergeSort(A,mid,right);
        t3=merge(A,left,mid,right);
        return t1+t2+t3;
    }
    return 0;
}
int main(){
   int A[500000];
   cin>>n;
   for(int i=0;i<n;i++)cin>>A[i];
   long long sum=mergeSort(A,0,n);
   cout<<sum<<endl;
   return 0; 
}
