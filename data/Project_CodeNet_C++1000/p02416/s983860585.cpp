#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    char ch[1000]="A";
    int num,i,a;
    while(true){
        scanf("%s",&ch);
        if(ch[0]=='0')break;
        i=0;
        num=0;
        while(true){
            if(ch[i]=='\0')break;
            a = ch[i]-'0';
            num += a;
            a=0;
            i+=1;
        }
        cout<<num<<endl;
    }
    return 0;
}
