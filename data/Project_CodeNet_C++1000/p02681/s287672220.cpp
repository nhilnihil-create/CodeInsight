#include<iostream>
#include<string>
using namespace std;

int main(){
int a;
string s, t, ans;
cin >> s >> t;
a = s.size();
ans = "Yes";
for(int i = 0;i < a;i++){
if(s.at(i) != t.at(i)){
ans = "No";
break;
}
}
cout << ans;
}

