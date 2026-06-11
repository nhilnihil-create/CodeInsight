#include <iostream>
using namespace std;

int main() {
 int a,b;
 cin>>a>>b;
 int p[b],s=0;
 for(int i=0;i<b;i++)
 {
     cin>>p[i];
     s+=p[i];
 } 
 if(s>=a) cout<<"Yes"<<endl;
 else cout<<"No"<<endl;
	 return 0;
}