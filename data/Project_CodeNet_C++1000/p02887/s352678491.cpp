#include <iostream>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
#define rep2(i,a,n) for(int i=a;i<=n;i++)
int main(void){
    // Your code here!
  int n;
  cin>>n;

 if(n==1)
    {
        cout<<n;
        return 0;
    }
    
string s;
cin>>s;
int count=1;
  for(int i=0;i<s.length()-1;i++){
     if(s[i+1]!=s[i])
        count++;
  }
  cout<<count;
}
