#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
int main(){
    string str1,str2,str3;
    int count,n;
    cin>>str1;
    while(1){
        str3="";
        cin>>str2;
        if(str2=="END_OF_TEXT"){
            break;
        }
        n=str2.size();
        for(int i=0;i<n;i++){
            str3+=tolower(str2[i]);
        }
        if(str3==str1){
            count++;
        }
    }
    cout<<count<<endl;
return 0;
}
