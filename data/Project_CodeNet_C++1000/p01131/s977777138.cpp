#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  string tmp[]={"",".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  string str;
  int i,l,cnt1,cnt2,n;
  cin >>n;
  for(int v=0;v<n;v++){
    cin >> str;
    l=str.size();
    cnt1=cnt2=0;
    for(int i=0;i<l;i++){
      if(str[i]=='0'){
	if(cnt2!=0){
	  cout << tmp[cnt1][(cnt2%tmp[cnt1].size()==0)?tmp[cnt1].size()-1:cnt2%tmp[cnt1].size()-1];
	}
	cnt1=cnt2=0;
      } else {
	if(cnt1==0){
	  cnt1=str[i]-'0';
	  cnt2++;
	}else{
	  cnt2++;
	}
      }
    }
    puts("");
  }
}