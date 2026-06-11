#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string N;
  cin>>N;
  if(N[N.size()-1]=='2'||N[N.size()-1]=='4'||N[N.size()-1]=='5'||N[N.size()-1]=='7'||N[N.size()-1]=='9'){
    cout<<"hon"<<endl;
  }
  else if(N[N.size()-1]=='3'){
    cout<<"bon"<<endl;
  }
  else{
    cout<<"pon"<<endl;
  }
}
