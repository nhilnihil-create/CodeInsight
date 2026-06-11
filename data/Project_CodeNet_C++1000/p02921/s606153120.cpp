#include<bits/stdc++.h>
using namespace std;

int main(){
    char s1[3],s2;
    int count=0;
    for(int i=0;i<3;i++){
        cin>>s1[i];
    }
    for(int i=0;i<3;i++){
        cin>>s2;
        if(s1[i]==s2)count++;
    }
    cout<<count;
}
