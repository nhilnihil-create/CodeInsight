#include <bits/stdc++.h>
#define fast_io ios :: sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main() {
	fast_io;
	string s;
    cin>>s;
    int count=0;
    vector<char>letter('Z');
     for(int i=0;i<s.size();i++){
          letter[s[i]]++;
     }
     for(int i:letter){
      if(i>=2)count++;
   if(count==2){
cout<<"Yes";
return(0);
   }
     }
        cout<<"No";
	return(0);
}

