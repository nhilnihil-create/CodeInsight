#include <bits/stdc++.h>
using namespace std;

int main(){
  long int n,a,b;
  cin >>n>> a>> b;
  /*vector<char>vec(n);
  long int p=0;
  for(int i=0;i<n;++i) cin >>vec[i];
  for(int i=0;i<n;++i){
    
    if(vec.at(i)==) {
    
      cout <<n<<endl;
    else if(n) cout <<n   */
  if(n<=a) cout << n<<endl;
  else if(n<=a+b) cout <<a<<endl;
  else{
    long int s,g ;
    s =n/(a+b);
    g=n%(a+b);
    if(g<=a) cout << s*a+g <<endl;
    else cout <<s*a+a <<endl;
  }
}