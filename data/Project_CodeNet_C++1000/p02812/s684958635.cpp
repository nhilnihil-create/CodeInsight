#include <iostream>
#include <string>
using namespace std;

int main()
{
   int n, count=0;
   cin>>n;
   string s;
cin>>s;
for(int j=0;j<n;j++){

    if(s[j]=='A' && s[j+1]=='B' && s[j+2]=='C'){
        count++;
    }

}
   cout<<count;
return 0;
}




