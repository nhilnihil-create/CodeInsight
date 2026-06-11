#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  char c;
  while((c=getchar())!='.'){
    if(c=='.')break;
    int cnthi=0;
    int cnthika=0;
    vector<int>hkf;
    bool ans=true;
    if(c=='('){cnthi++;hkf.pb(1);}
    else if(c=='['){cnthika++;hkf.pb(2);}
    else if(c==')')ans=false;
    else if(c==']')ans=false;
    char c2;
    while((c2=getchar())!='\n'){
      if(c2=='('){cnthi++;hkf.pb(1);}
      else if(c2=='['){cnthika++;hkf.pb(2);}
      else if(c2==')'){cnthi--;if(hkf.empty()){ans=false;}
	else if(hkf[hkf.size()-1]==1){hkf.pop_back();}
	else if(hkf[hkf.size()-1]!=1){ans=false;}}
      else if(c2==']'){cnthika--;if(hkf.empty()){ans=false;}
	else if(hkf[hkf.size()-1]==2){hkf.pop_back();}
	else if(hkf[hkf.size()-1]!=2){ans=false;}
      }
      if(cnthi<0||cnthika<0)
	ans=false;
    }
    if(cnthi!=0||cnthika!=0)
      ans=false;
    if(ans)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
  return 0;
}