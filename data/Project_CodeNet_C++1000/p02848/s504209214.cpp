#include<bits/stdc++.h>
using namespace std;

main()
{
  //  ios::sync_with_stdio(0);
 //   cout.tie(0);
 //   cin.tie(0);
    long long i,j,k,l,m,n,o,p;

    string s;

   while(cin>>n>>s){
    l=s.size();
    k=90-n;
    for(i=0;i<l;i++){
        if(s[i]>k){
            j=n-(90-s[i]);
            printf("%c",64+j);
        }
        else printf("%c",s[i]+n);
    }
    cout<<endl;
   }

    return 0;

}
