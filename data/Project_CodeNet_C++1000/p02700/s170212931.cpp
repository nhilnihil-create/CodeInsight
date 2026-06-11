#include<bits/stdc++.h>
using namespace std;

int main(){
  double a,b,c,d;
  cin >> a>>b>> c>>d;
  if(ceil(c/b)<=ceil(a/d)){
    cout << "Yes"<<endl;
  }else{
    cout <<"No"<<endl;
  }
}
