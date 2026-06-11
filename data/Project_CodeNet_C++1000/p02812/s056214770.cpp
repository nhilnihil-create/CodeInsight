#include<iostream>
#include<math.h>
#include<algorithm>
typedef long long ll;
using namespace std;
int n,c;
char s[55];
int main(){	
cin>>n;
for(int i=0;i<n;i++)
cin>>s[i];
for(int i=0;i<n;i++){
if(s[i]=='B'){
	if(s[i-1]=='A'&&s[i+1]=='C')
	c++;
}
}
cout<<c;
return 0;
} 