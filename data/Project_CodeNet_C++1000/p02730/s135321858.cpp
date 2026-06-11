#include <bits/stdc++.h>
using namespace std;

int main(){
   char A[100];
   cin>>A;
   int n=strlen(A)/2;
   int i;
   for(i=0;i<n;i++){
       if(A[i]!=A[n+1+i]){printf("No");return 0;}
   }
   int s=n/2;
   for(i=0;i<s;i++){
       if(A[i]!=A[n-1-i]){printf("No");return 0;}
   }
   printf("Yes\n");
}
