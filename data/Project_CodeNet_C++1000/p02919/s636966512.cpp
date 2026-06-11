#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  cin >> a;
  vector<int> x(a);
  for(int i = 0;i < a;i++){
    cin >> x.at(i);}
  long long v=0;
  vector<int> one(a);
  int mmm=0;
  for(int i = 0;i < a;i++){
    if(mmm < x.at(i)){mmm = x.at(i);
                      one.at(i) = 1;}
  }
  vector<int> two(a);
  int mmmm = 0;
  for(int i = a-1;i > -1;i--){
    if(mmmm < x.at(i)){mmmm = x.at(i);
                      two.at(i) = 1;}
  }
  for(int i = 0;i < a;i++){
    long long p=1;
    long long q=0;
    long long r=1;
    long long s=0;
    int fone=0;
    int ftwo=0;
    if(one.at(i) == 1)p=i+1;
    else{
    for(int j = i-1;j > -1;j--){
      if(fone==0 && x.at(i)<x.at(j)){q++;fone++;}
      else if(fone==0)p++;
      else if(x.at(i)<x.at(j))break;
      else if(fone==1)q++;
    }
    }
    if(two.at(i) == 1)r=a-i;
    else{
    for(int j = i+1;j < a;j++){
      if(ftwo==0 && x.at(i)<x.at(j)){s++;ftwo++;}
      else if(ftwo==0)r++;
      else if(x.at(i)<x.at(j))break;
      else if(ftwo==1)s++;
    }
    }
    v += (p*s+q*r)*x.at(i);
  }
      cout << v << endl;
}