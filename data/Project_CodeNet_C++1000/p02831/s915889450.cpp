#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll int a,b,q=0,i=1;
    cin>>a >>b;
    while(i<=INT_MAX){
      if((max(a,b))*i%a==0 && max(a,b)*i%b==0){
        q=max(a,b)*i;
        break;
      }
      else{i++;continue;}
      i++;
    }
    cout<<q <<endl;
}


