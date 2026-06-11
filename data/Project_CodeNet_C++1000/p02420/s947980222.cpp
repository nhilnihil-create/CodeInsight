#include<iostream>
#include<string>
using namespace std;

int main( ){
  while(1){
    int n,s,sum=0;
    string a;
    cin>>a>>n;
    if(a=="-")break;
    for(int i=0;i<n;i++){
      cin>>s;
      sum+=s;
    }
    sum%=a.size();
    a=a+a.substr(0,sum);
    a=a.erase(0,sum);
    cout<<a<<endl;
  }
  return 0;
}