#include <bits/stdc++.h>
using namespace std;

int main() {int N;
  cin>>N;
  string S[N];
  int t[N];
  int i=0;
  while(i<N){cin >> S[i] >> t[i];
            i++;}
string x;
  cin>>x;
  int sum=0;
for(int j=0;j<N;j++){
  if(x==S[j]){
    for(int k=j+1;k<N;k++){sum +=t[k];}
  	break;	}
	}
cout<<sum<<endl;  // ここにプログラムを追記
}
