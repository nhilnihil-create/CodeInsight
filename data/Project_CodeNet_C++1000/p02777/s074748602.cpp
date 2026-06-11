#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;

    string s1,s2,s3;
    cin>>s1>>s2;
    cin>>a>>b;
    cin>>s3;
    if(s3.compare(s1)==0){
        a--;
    }
    else if(s3.compare(s2)==0){
        b--;
    }
    if(a<0){
        a=0;
    }
    if(b<0){
        b=0;
    }
    cout<<a<<" "<<b<<endl;




}







