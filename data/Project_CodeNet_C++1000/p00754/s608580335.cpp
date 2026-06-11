#include <iostream> // C++の入出力
#include <stdio.h> // C の入出力
#include <algorithm> // sort などのアルゴリズム
#include <string.h> // C の文字列用
#include <ctype.h> // C の文字種用
#include <string> // C++の文字列
using namespace std;
int main(void){
    string ken="()[]";
    while(1){
        bool frg=true;
        string in,nate="";
        getline(cin,in);
        if(in==".")break;
        for(int s=0;s<in.length();s++){
            if(in[s]==ken[0]||in[s]==ken[2]){
                nate+=in[s];
            }
            if(in[s]==ken[1]){
                if(nate[nate.length()-1]==ken[0]){
                    string work=nate;
                    nate="";
                    for(int i=0;i<work.length()-1;i++){
                        nate+=work[i];
                    }
                }else{
                    frg=false;
                    break;
                }
            }
            if(in[s]==ken[3]){
                if(nate[nate.length()-1]==ken[2]){
                    string work=nate;
                    nate="";
                    for(int i=0;i<work.length()-1;i++){
                        nate+=work[i];
                    }
                }else{
                    frg=false;
                    break;
                }
            }
        }
        if(frg&&nate=="")cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}