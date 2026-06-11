#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

   int n;
   cin>>n;
   bool ok = false;
   for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
        if(i*j==n){
            ok =true;
            break;
        }
    }
   }
   if(ok )cout<<"Yes";
   else cout<<"No";


return 0;
}

