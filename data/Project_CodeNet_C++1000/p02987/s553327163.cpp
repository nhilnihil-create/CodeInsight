#include <iostream>
#include <string>
using namespace std;

int main(){
string s;
char ary[4];
bool f=0;
for(int i=0; i<4; i++){
cin >> ary[i];
}
int cnt=0;
for(int i=0; i<4; i++){//全ての要素が等しいか 
if(ary[0]==ary[i]) cnt++; //全ての要素が等しい時4になる
}
  if(ary[0]==ary[1] && ary[2]==ary[3]) f=1;  //aabb
else if(ary[0]==ary[2] && ary[1]==ary[3])f=1; //abab
  else if(ary[0]=ary[3] && ary[1]==ary[2]) f=1; //abba

  if(cnt==4) cout <<"No" <<endl;
else if(f)cout <<"Yes" <<endl;
else cout <<"No" <<endl;
return 0;
}
