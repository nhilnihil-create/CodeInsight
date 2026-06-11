#include<bits/stdc++.h>
using namespace std;
int main(){
 string s;
 cin>>s;
 set<char> t;
 for(int i=0;i<4; i++){
     t.insert(s.at(i));
 }
 if(t.size()==2) cout<<"Yes"<<endl;
 else cout<<"No"<<endl;
return 0;
}