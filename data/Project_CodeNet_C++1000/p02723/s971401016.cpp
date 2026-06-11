#include<bits/stdc++.h>
using namespace std;
int main(void){
string s ; cin>>s ;
if(s.length()==6){
char x[7];
strcpy(x,s.c_str());
bool b = 0;
for(int i=0 ; i<2 ; i++){
    if(int(x[i])<97||int(x[i])>122)
        {b = 1;break;}
}
if(b==0&&x[2]==x[3]&&x[4]==x[5])
    cout<<"Yes"<<endl;
else
    cout<<"No"<<endl;

}

return 0;}
