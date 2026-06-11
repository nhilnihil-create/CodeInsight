#include<bits/stdc++.h>
using namespace std;
int main(void){
string s,t;cin>>s>>t;
char x[4],y[4];
int count1 = 0;
strcpy(x,s.c_str());strcpy(y,t.c_str());
for(int i=0;i<3;i++){
    if(x[i]==y[i])
        count1+=1;
}
cout<<count1<<endl;
return 0;}
