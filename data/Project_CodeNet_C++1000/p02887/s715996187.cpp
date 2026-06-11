#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
  string s;
  cin>>s;
  vector<char>arr;
  for(int i=0; s[i]; i++) arr.push_back(s[i]);
  arr.erase(unique(arr.begin(),arr.end()),arr.end());
  cout<<arr.size();
}