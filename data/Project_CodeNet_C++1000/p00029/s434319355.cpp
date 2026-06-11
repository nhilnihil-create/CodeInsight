#include <iostream>
#include <map>
#include <string>
using namespace std; map<string,int>RB;int main() {string T;while ((cin>>T)!=NULL) {for (int i=T.length()-1;i>=0;i--) if (T[i]<='Z') T[i]+=32;RB[T]++;}
map<string,int>::iterator it=RB.begin(),ot=it++;for (;it!=RB.end();it++) if ((it->second)>(ot->second)) ot=it;cout<<ot->first<<" ";it=RB.begin();ot=it++;for (;it!=RB.end();it++) if ((it->first).length()>(ot->first).length()) ot=it;cout<<ot->first<<endl;return 0;}