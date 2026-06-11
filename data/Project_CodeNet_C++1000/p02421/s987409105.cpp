#include<iostream>
//#include <stdio.h>
#include <cstdio>
//#include<string>
#include <cstring>
using namespace std;

int main(void){
    int n;
    int taro=0,hanako=0;
    char string1[101],string2[101];
    cin >> n;

    for(int i = 0;i<n;i++){
        cin >> string1 >> string2;
        if(strcmp(string1,string2)==0){
            taro++;
            hanako++;

        }else if(strcmp(string1,string2)>0){
            taro+=3;
            //taro=taro+3;
        }else{
            hanako+=3;
            //hanako=hanako+3;
        }

    }
    cout << taro << " " << hanako << endl;
}
