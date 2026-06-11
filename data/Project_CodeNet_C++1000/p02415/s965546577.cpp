#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
int main(){
    char ch='A',x='A';
    int k=0;
    while(k<1200){
        
        scanf("%c",&ch);
        if(ch== '\n')break;
        if(isalpha(ch)){
            if(islower(ch)){
                x=toupper(ch);
            }else{
                x=tolower(ch);
            }
            printf("%c",x);
        }else{
            printf("%c",ch);
        }
        k+=1;
        
    }
    cout<<endl;
    return 0;
}
