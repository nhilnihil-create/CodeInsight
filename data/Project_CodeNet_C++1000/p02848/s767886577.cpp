#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
///                    BISMILLAHIR RAHMANIR RAHIM

int main()
{
   int n;
   cin>>n;
   string s;
   cin>>s;
   int l=s.length();
   for(int i=0;i<l;i++){
    int r=s[i]+n;
    if(r>90)
        r=r-26;
    printf("%c",(r));
   }
   cout<<endl;

}



/// A L H A M D U L I L L A H
