#include<iostream>
using namespace std;

int main(){
    int alpha[26];
    for(int a=0;a<26;a++)alpha[a]=0;

    char ch;
    while(cin>>ch){

        for(int i=0;i<26;i++){
            if(ch-'a'==i)alpha[i]++;
            else if(ch+32-'a'==i)alpha[i]++;
        }
    }

    for(int i=0;i<26;i++){
        cout<<(char)(i+'a')<<" : "<<alpha[i]<<endl;
    }

    return 0;
}
