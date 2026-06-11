#include<bits/stdc++.h>
using namespace std;
int main(){
  string str;
  int q;
  string m,p;
  int a,b,j,k;
  cin>>str;
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>m>>a>>b;
    if(m=="replace"){
      cin>>p;
      for(int j=a;j<=b;j++){
	str[j]=p[j-a];
      }
    }
    else if(m=="reverse"){
      j=a;
      k=b;
      while(j<k){
	swap(str[j],str[k]);
	j++;
	k--;
      }
    }
    else if(m=="print"){
      for(int j=a;j<=b;j++){
	cout<<str[j];
      }
      cout<<endl;
    }
  }
  return 0;
}

