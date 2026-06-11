#include<bits/stdc++.h>

using namespace std;

int main(){
string a;
cin >> a;
int len = a.length();
for(int i = 1; i <=len;++i){
if(i&1 && a[i-1]=='L'){
cout<<"No";
return 0;
}
if(!(i&1) && a[i-1]=='R'){
cout<<"No";
return 0;
}
}
cout << "Yes";
return 0;
}
