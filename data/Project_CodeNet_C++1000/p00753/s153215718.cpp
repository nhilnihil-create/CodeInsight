#include<iostream>
using namespace std;

string prime(int n){
  int i,j;
  string p = "001";
  while((int)p.size()<=n)p+="10";
  i = 3;
  while(i*i<n){
    for(j=3*i;j<n;j+=2*i)p[j] = '0';
    do{i+=2;}while(p[i]-'1');
  }
  return p;
}

int main(){
  int n,c;
  string p;

  p = prime(300000);

  while(1){
    cin >> n;
    if(!n)break;

    c = 0;
    for(int i=n+1;i<=2*n;i++){
      if(p[i] == '1'){
	c++;
      }
    }
    
    cout << c << endl;
  }
}