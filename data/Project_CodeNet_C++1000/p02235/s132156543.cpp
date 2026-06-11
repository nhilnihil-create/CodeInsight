#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

int mem[1005][1005];

void pre(int x,int y){
  for(int i=0;i<=x;i++){
    for(int j=0;j<=y;j++){
      mem[i][j]=0;
    }
  }

  return;
}

main(){
  int n;
  string temp;
  string x,y;

  cin >> n;
  
  for(int cnt=0;cnt<n;cnt++){
    
    x="0";
    y="0";
    cin >> temp;
    x+=temp;
    cin >> temp;
    y+=temp;

    pre((int)x.size(),(int)y.size());

    for(int i=1;i<=x.size();i++){
      for(int j=1;j<=y.size();j++){

	if(x[i]==y[j]){
	  mem[i][j]=mem[i-1][j-1]+1;
	}
	mem[i][j]=max(mem[i][j],max(mem[i-1][j],mem[i][j-1]));

      }
    }

    cout << mem[x.size()][y.size()]-1 << endl;
  }

  return (0);
}

