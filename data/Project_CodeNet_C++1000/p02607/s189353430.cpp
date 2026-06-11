#include <iostream>

using namespace std;

int main(){
   int n, c=0; cin>>n;
   int ar[n];
   for (int i=0; i<n; i++){
        cin>>ar[i];
        if (ar[i]%2==1 && (i+1)%2==1) c++;
   }
   cout<<c;
}