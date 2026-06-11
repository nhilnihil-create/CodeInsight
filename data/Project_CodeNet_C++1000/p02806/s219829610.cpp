#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  map<string,int>mp;
  vector<int> T(n);
  for(int i=0;i<n;i++){
    string s;
    int t;
    cin>>s>>t;
    mp[s]=i;
    T[i]=t;
  }
  string x;
  cin>>x;
  int sum=0;
  for(int i=mp[x]+1;i<n;i++)sum+=T[i];
  cout<<sum<<endl;
}
