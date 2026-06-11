#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,n,temp,pointer=1;
  cin>>x>>n;
  set<int> main;
  if(n){
  for(int i=0;i<n;i++){
    cin>>temp;
    main.insert(temp);
  }
  for(int i=0;i<n;i++){
  
  if(main.count(x)==0){
    cout<<x<<'\n';break;
  }else{
  if(main.count(x-pointer)==0){ cout<<x-pointer<<'\n';break;

  }else if(main.count(x+pointer)==0){ cout<<x+pointer<<'\n';break;

  }else pointer++;
  
  }
  }
  
  }else cout<<x<<'\n';

}
