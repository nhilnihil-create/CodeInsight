#include<bits/stdc++.h>
using namespace std;

int main(){
    char s1[4];
    char s2[4];
    cin>>s1;
    getchar();
    cin>>s2;
    int count=0;
    for(int i=0;i<3;i++){
        if(s1[i]==s2[i])
        count++;
    }
    cout<<count<<endl;

}