#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;

int main(){
    char a,b;
    cin>>a;
    b='A';
    string s="qwertyuiopasdfghjklzxcvbnm";
    for(int i=0;i<s.size();i++){
        if(s[i]==a){
            b='a';
        }
    }
    cout<<b<<endl;
}
