#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
    int l,m,i,c=0;
    string s;
   cin>>l;
    cin>>s;
      m=l/2;
    if(l%2!=0){
        cout<<"No";
        return 0;
    }
        else{
            for(i=0;i<m;i++){
                if(s[i]==s[i+m]){
                c++;
                }
            }
            if(c==m)
                cout<<"Yes";
            else
                cout<<"No";
        }




}
