#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int X;
  int Y;
  int Z;
  cin>>X;
  cin>>Y;
  cin>>Z;
  swap(X,Y);
  swap(X,Z);
  cout<<X;
  cout<<" ";
  cout<<Y;
  cout<<" ";
  cout<<Z;
}