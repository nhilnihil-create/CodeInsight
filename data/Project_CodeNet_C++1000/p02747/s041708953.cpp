#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    string s;
    cin>>s;
    bool b=true;
    int h=0, ii=0;
    for(int i=0; i<s.length(); i++){
        if(i%2==0 && s[i]!='h' )  {b=false; break;}
        else if(i%2!=0 && s[i]!='i') {b=false; break;}
        h+= (s[i]=='h');
        ii+= (s[i]=='i');
 
    }

    cout<<(b && (h==ii) ? "Yes" : "No");
}
