#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<stack>
#include<queue>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;


using namespace std;



int main()
{

  while(true){
    string text;
    getline(cin,text);

    if(text=="."){
      break;
    }

    stack<char> kakko;
    bool flag=true;

    for(int i=0;i<text.length();i++){
      
      //cout << text[i] << endl;
      
      if(text[i]=='('||text[i]=='['){
        kakko.push(text[i]);
      }


      if(text[i]==')'||text[i]==']'){
       if(kakko.empty()){
          flag = false;
          break; 
        }else if((kakko.top()=='(' && text[i]==']')||((kakko.top()=='[' && text[i]==')'))){
          flag = false;
          break;
        }else{
          kakko.pop();
        }
      }

    }
    
    if(!kakko.empty()){
      flag = false;
    }
    
    if(flag){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }

  }

  return 0;
}