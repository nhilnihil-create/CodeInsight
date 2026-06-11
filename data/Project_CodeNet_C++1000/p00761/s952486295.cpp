#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

const int I = 21;

int str2int(string str) {
  stringstream ss;
  int ans;

  ss<<str;
  ss>>ans;

  return ans;
}

string int2str(int num) {
  stringstream ss;

  ss<<num;

  return ss.str();
}

int checker(int ai[], int j) {
  int flag = -1;

  for(int i=0; i<j && flag==-1; i++) {
    if(ai[i] == ai[j]) {
      flag = i;
    }
  }

  return flag;
}

int main() {

  string tmp;
  int  l;

  cin>>tmp>>l;

  while(tmp!="0" || l!=0) {
    string as;
    int ai[I] = {0};
    as = tmp;
    while(as.length() < l) {
      as += "0";
    }

    ai[0] = str2int(as);

    int flag = -1;
    int j=1;
    while(flag == -1) {
      string big=as, small=as;
      sort(big.begin(), big.end(), greater<int>());
      sort(small.begin(), small.end());

      ai[j] = str2int(big)-str2int(small);
      as = int2str(ai[j]);
      while(as.length() < l) {
	as += "0";
      }
      
      /*
      for(int i=0; i<=j; i++) {
	cout<<"ai["<<i<<"] = "<<ai[i]<<endl;
      }
      cout<<endl;
      */
      
      flag = checker(ai, j);

      //cout<<"ai["<<j<<"] = "<<ai[j]<<endl;
      //cout<<as<<endl;

      j++;
    }

    cout<<flag<<" "<<ai[flag]<<" "<<j-flag-1<<endl; // ループの最後で j が増えているために-1が必要

    cin>>tmp>>l;
  }
  
}