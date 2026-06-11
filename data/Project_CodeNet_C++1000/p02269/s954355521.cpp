#include<iostream>
#define M 1000003
#define f first
#define s second
using namespace std;
int n,c[256];
int f[M];

int stoi(string s){
  int res=0;
  for(int i=0;i<s.size();i++)res*=5,res+=c[s[i]];
  return res;
}

int func1(int a){
  return a%M;
}

int func2(int a){
  return 1+a%(M-1);
}

int main(){
  string mei,str;
  c['A']=1,c['C']=2,c['G']=3,c['T']=4;
  cin>>n;
  while(n--){
    cin>>mei>>str;
    int a=stoi(str);
    int b=func1(a),c=func2(a);
    if(mei[0]=='i'){
      while(f[b])b+=c,b%=M;
      f[b]=a;    
    }
    if(mei[0]=='f'){
      int cn=0,fg=0;
      while(cn!=M&&f[b]!=a){
	b+=c,b%=M,cn++;
	if(!f[b]){fg=1;break;}
      }
      if(cn==M||fg)cout<<"no"<<endl;
      else cout<<"yes"<<endl;
    }
  }
  return 0;
}