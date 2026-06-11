#include <iostream>
using namespace std;

int partition(int A[],int p,int r){
   int x=A[r];
   int i=p-1;
   for(int j=p;j<=r-1;j++){
      if(A[j]<=x){
          i=i+1;
          int a;
          a=A[i];
          A[i]=A[j];
          A[j]=a;
      }
   }
   int b;
   b=A[i+1];
   A[i+1]=A[r];
   A[r]=b;
   return i+1;
}

int main(){
   int n;
   cin >> n;
   int A[100000];
   for(int i=0;i<n;i++)
      cin >> A[i];
   int p=partition(A,0,n-1);
   for(int i=0;i<n;i++){
      if(i==p)
         cout << '[' << A[i] << ']';
      else
         cout << A[i];
      if(i<n-1)
         cout << ' ';
      else
         cout << endl;
   }
   return 0;
}