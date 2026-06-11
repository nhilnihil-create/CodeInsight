#include<iostream>
#include<sstream>

using namespace std;

string byeFront(string str) {
  string ans;
  for(int i=1; i<str.length(); i++) {
    ans += str[i];
  }
  return ans;
}

int toInt(string str) {
  int ans = 0;
  int tmp = 1;
  for(int i=0; i<str.length(); i++) {
    if(str[i] == 'm') {
      ans += tmp*1000;
      tmp = 1;
      //cout<<"m"<<endl;
    }
    else if(str[i] == 'c') {
      ans += tmp*100;
      tmp = 1;
      //cout<<"c"<<endl;
    }
    else if(str[i] == 'x') {
      ans += tmp*10;
      tmp = 1;
      //cout<<"x"<<endl;
    }
    else if(str[i] == 'i') {
      ans += tmp;
      tmp = 1;
      //cout<<"i"<<endl;
    }
    else {
      stringstream ss;
      ss<<str[i];
      ss>>tmp;
      //cout<<"++"<<endl;
    }
    //cout<<ans<<endl;
  }
  return ans;
}

string toMCXI(int num) {
  string ans, str;
  stringstream ss;
  ss<<num;
  ss>>str;
  
  string nextStr;
  if(str.length() == 4) {
    nextStr = "m";
  }
  else if(str.length() == 3) {
    nextStr = "c";
  }
  else if(str.length() == 2) {
    nextStr = "x";
  }
  else if(str.length() == 1) {
    nextStr = "i"; 
  }
  
  int orgLength = str.length();
  string strrr = str;
  for(int i=0; i<orgLength; i++) {
    //cout<<str[i]<<"!";
    if(str[i]!='0' && str[i]!='1') {
      ans += str[i];
      ans += nextStr;
    }
    else if(str[i] == '1') {
      ans += nextStr;
    }

    strrr = byeFront(strrr);
    if(strrr.length() == 3) {
      nextStr = "c";
    }
    else if(strrr.length() == 2) {
      nextStr = "x";
    }
    else {
      nextStr = "i";
    }
    //cout<<i<<" : "<<ans<<endl;
  }
  return ans;
}

int main() {
  /*
  string sampleStr = "m2ci";
  cout<<sampleStr<<endl;
  cout<<toInt(sampleStr)<<endl;
  cout<<toMCXI(toInt(sampleStr))<<endl;
  */

  int n;
  cin>>n;
  for(int i=0; i<n; i++) {
    string strA, strB;
    cin>>strA>>strB;
    int numA = toInt(strA);
    int numB = toInt(strB);
    //cout<<strA<<endl;
    //cout<<numA<<endl;
    cout<<toMCXI(numA+numB)<<endl;
  }
}