#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(){

int N,c=0,i,X;

cin >> N;

for(i=0;i<=N;i++){
  X=i*1.08;
  if(N==X){
    c=1;
    break;
  }

}

if(c){
  cout << i << endl;
}
else{
  cout << ":(" << endl;
}

}
