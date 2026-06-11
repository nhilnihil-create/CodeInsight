#include <iostream>
using namespace std;

int main() {
int n,r=0,c=0;
cin>>n;
string s;
cin>>s;
for(int i=0;i<n;i++){
    if(s[i]=='R'){
        r++;
    }
}
for(int j=0;j<r;j++){
     if(s[j]=='R'){
         c++;
     }
}
cout<<r-c;

	return 0;
}