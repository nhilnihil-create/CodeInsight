#include<bits/stdc++.h>
using namespace std;
 int main(){
string str,ans;
int n;
cin >> n;
cin >> str;
if(n<str.size()){
for(int i=0;i<n;i++){
ans.push_back(str[i]);
}
for(int i=0;i<3;i++)ans.push_back('.');
}
else{
ans=str;
}
cout << ans;
}
