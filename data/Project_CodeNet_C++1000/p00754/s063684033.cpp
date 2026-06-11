#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=1;i<n;i++)
#define lpin(a,i,n) for(int i=0;i<n;i++){cin>>a[i];}

int main(){
  while(1){
    char x;
    int a=0,b=0,de[150],ch=0,f=0,it=0;
    if(f=0){
      f=1;
    }
    else  scanf("%c",&x);
    scanf("%c",&x);
    if(x=='.') break;
    while(1){
      if(x=='(') {
	a++;
	
	it++;
	de[it]=1;
      }
      if(x==')') {
	if(de[it]==1){
	  a--;
	  it--;
	}
	else{ch=1;}
      }
      if(x=='['){
	b++;
	it++;
	de[it]=2;
      }
      if(x==']'){
	if(de[it]==2){
	  b--;
	  it--;
	}
	else{ch=1;}
      }
      if(a<0 || b<0){
	ch=1;
      }
      scanf("%c",&x);
      if(x=='.') break;
    }
    if(ch==0 &&a==0 && b==0) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
  return 0;
}

