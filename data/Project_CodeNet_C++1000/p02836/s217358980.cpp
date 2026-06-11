#include<bits/stdc++.h>

using namespace std;

int main(){
 #ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
  freopen ("outt.txt", "w", stdout);

#endif
  
   long long mod = 1000000007;


string s;
cin>>s;
int n= s.length();

int i=0,j=n-1;
int cnt=0;
while(i<=j){
  if(s[i]!=s[j]){
cnt++;
  }
  i++;
  j--;
}

cout<<cnt<<endl;


return 0;
}