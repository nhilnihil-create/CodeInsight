#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  vector<vector<char> > v;
  vector<char> mv;

  mv.push_back(' ');mv.push_back('.');mv.push_back(',');mv.push_back('!');mv.push_back('?');
  v.push_back(mv);
  mv.clear();

  mv.push_back('c');mv.push_back('a');mv.push_back('b');
  v.push_back(mv);
  mv.clear();

  mv.push_back('f');mv.push_back('d');mv.push_back('e');
  v.push_back(mv);
  mv.clear();

  mv.push_back('i');mv.push_back('g');mv.push_back('h');
  v.push_back(mv);
  mv.clear();

  mv.push_back('l');mv.push_back('j');mv.push_back('k');
  v.push_back(mv);
  mv.clear();

  mv.push_back('o');mv.push_back('m');mv.push_back('n');
  v.push_back(mv);
  mv.clear();

  mv.push_back('s');mv.push_back('p');mv.push_back('q');mv.push_back('r');
  v.push_back(mv);
  mv.clear();

  mv.push_back('v');mv.push_back('t');mv.push_back('u');
  v.push_back(mv);
  mv.clear();

  mv.push_back('z');mv.push_back('w');mv.push_back('x');mv.push_back('y');
  v.push_back(mv);
  mv.clear();

  string s;
  int a,i,cou,n,cou2,b;
  cin >>b;
  for(int j=0;j<b;j++){ // 入力
    cin>>s;
    a=s.size();
    //cout <<a<< ' ';//////////////////
    i=0;
    cou2=0;
    while(i<a){//改行まで
      cou=0;
      n=0;
      while(s[i]!='0'&&i<a){//０まで
	if(n!=s[i]-'0')cou=0;
	n=s[i]-'0';
	i++;
	cou++;
      }
      i++;
      //cout <<n<< cou<< ' ';/////////////////
      if(cou!=0&&i<=a){
	if(n==8||n==2||n==3||n==4||n==5||n==6)cou=cou%3;
	else if(n==7||n==9)cou=cou%4;
	else if(n==1)cou=cou%5;

	cout<<v[n-1][cou];
	cou2++;
      }
    }
    if(cou2!=0)cout<<endl;
  }
  return 0;
}