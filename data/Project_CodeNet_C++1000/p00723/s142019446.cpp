#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

typedef set<string> set_t;
set_t A;

int organize(string str1,string str2){
  A.insert(str1+str2);
  A.insert(str2+str1);
}


int main(){
  int k;
  cin >> k;
  string train;
  for(int i=0;i<k;i++){
    cin >>train;
    int len = train.length();
    for(int j =0;j<len-1;j++){
      string str1;
      string str2;
      for(int l=0;l<=j;l++){
	str1+=train[l];
      }
      for(int l=j+1;l<len;l++){
	str2+=train[l];
      }
      organize(str1,str2);
      reverse(str1.begin(),str1.end());
      organize(str1,str2);
      reverse(str2.begin(),str2.end());
      organize(str1,str2);
      reverse(str1.begin(),str1.end());
      organize(str1,str2);
    }
    cout << A.size() << endl;
    A.clear();
  }
}