#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
    cin>>s;
    int count=1;
    int maximum=0;
     for(int i=0;i<s.size();i++){
        if(s[i]=='R'){
          if(s[i+1]=='R'){
            count++;
          }
          else{
            maximum=max(maximum,count);
            count=1;
       }
     }
}
    cout<<maximum;
	return 0;
}