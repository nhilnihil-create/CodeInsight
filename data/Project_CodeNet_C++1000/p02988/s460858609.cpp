#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
int n;
  cin>>n;
  vector<int>moji(n);
rep(i,n)  cin>>moji.at(i);
  int counter=0;
rep(i,n-2){
	if(moji.at(i)< moji.at(i+1) &&moji.at(i+1)<moji.at(i+2)) counter++;
  	else if(moji.at(i)>moji.at(i+1) && moji.at(i+2)<moji.at(i+1))counter++;
}
  cout<<counter<<endl;
}