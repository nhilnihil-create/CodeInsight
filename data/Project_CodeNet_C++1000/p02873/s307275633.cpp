#include <bits/stdc++.h>
using namespace std;
 
int main() {
 string S;
 cin >>S;
 vector<long long>aaa(S.size()+1,0);
 long long answer=0;
 for(long long i=0;i<S.size();i++){
     if(S.at(i)=='<'){
         aaa.at(i+1)=aaa.at(i)+1;
     }
 }
 for(long long i=S.size()-1;0<=i;i--){
     if(S.at(i)=='>'){
         if(aaa.at(i+1)>=aaa.at(i)){
             aaa.at(i)=aaa.at(i+1)+1;
         }
     }
 }
for(int i=0;i<=S.size();i++){
    answer+=aaa.at(i);
}
cout<<answer<<endl;
}