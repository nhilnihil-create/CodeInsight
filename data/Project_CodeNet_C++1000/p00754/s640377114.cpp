#include<iostream>
#include<cstdio>

using namespace std;

int main(void){
  char r[1000000];
  int count = 101;
  char s;
  char c;
  int maru=0;
  int shikaku=0;
  while(true){
    //はじめの文字の判定
    scanf("%c",&s);
    if(s=='\n')scanf("%c",&s);
    if(s=='.')break;
    else if(s=='('){
      r[count++]=')';
      maru++;
    }
    else if(s=='['){
      r[count++]=']';
      shikaku++;
    }
    else if(s==')'){
  	maru=-111;

    }
    else if(s==']'){
      shikaku=-111;
    }
    //終了条件ではないとき
    while(true){
      cin>>c;
      //    cout<<c;
      if(c=='.'||maru<0||shikaku<0)break;
      else if(c=='('){
	r[count++]=')';
	maru++;
      }
      else if(c=='['){
	r[count++]=']';
	shikaku++;
      }
      else if(c==')'){
	if(r[count-1]==c){
	  count--;
	  maru--;
	}
	else maru=-111;
      }
      else if(c==']'){
	if(r[count-1]==c){
	  count--;
	  shikaku--;
	}
	else shikaku=-111;
      }
    }
   if(c!='.'){
      while(true){
	cin>>c;
	//    cout<<c;
	if(c=='.')break;
      }
   }
   if(maru==0&&shikaku==0)cout<<"yes"<<endl;
   else cout<<"no"<<endl;
   maru=0;
   shikaku=0;
  }
  return 0;
}