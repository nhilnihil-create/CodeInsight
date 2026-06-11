#include<iostream>
#include<string>

using namespace std;

string hyo[]={".,!? ",
	      "abc",
	      "def",
	      "ghi",
	      "jkl",
	      "mno",
	      "pqrs",
	      "tuv",
	      "wxyz",};

main(){
  string in;
  int n;
  cin>>n;
  while(n--){
    cin>>in;
    string out;
    int zen='0';
    int c=0;
    for(int i=0;i<in.size();i++){
      if(in[i]=='0' && zen!='0'){
	zen-='1';
	int s=hyo[zen].size();
	--c;
	c%=s;
	out+=hyo[zen][c];
	c=0;
	zen=in[i];
      }else if(in[i]=='0' && zen=='0'){
	continue;
      }else if(zen=='0' && in[i]!=0){
	c=1;
	zen=in[i];
      }else if(in[i]==zen){
	++c;
      }
    }
    cout<<out<<endl;
  }
}