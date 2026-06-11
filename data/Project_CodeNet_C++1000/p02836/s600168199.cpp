#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int i,j,count=0;
    int x=s.size();
    for(i=0,j=x-1;i<=j;i++,j--){
        if(s[i]!=s[j])
        count++;
    }
    cout<<count<<endl;
}
