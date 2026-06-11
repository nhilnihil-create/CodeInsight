#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
   ll a,b;
   cin>>a>>b;
   for(int i=1;i<=1e4; ++i){
    int tax1 = i*8/100; int tax2 = i*10/100;
    if(tax1==a && tax2==b){
        cout<<i;
        return 0;
    }
   }
   cout<<-1;

}
