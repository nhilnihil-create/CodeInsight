#include <bits/stdc++.h>
using namespace std;
int main(void){
    string str1,str2,str3;
    cin>>str1;
    
    for(int i=0; i<(str1.length()-1)/2; i++){
        str2+=str1[i];
    }
    for(int i=(str1.length()+3)/2-1; i<str1.length(); i++){
        str3+=str1[i];
    }
    
    string rs1=str1, rs2=str2, rs3=str3;
    reverse(rs1.begin(), rs1.end());
    reverse(rs2.begin(), rs2.end());
    reverse(rs3.begin(), rs3.end());
    
    if(str1==rs1 && str2==rs2 && str3==rs3){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}