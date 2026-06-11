#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb   push_back
#define T int time;        scanf("%d", &time); while(time--)
    struct aray{
        ll a,b;
    };
//aray a[10000],b[100000];
int main(){
     //T{
      string s;
      cin>>s;
      if(s[s.size()-1] == 's')   s+="es";
    else if( s[s.size()-1] != 's' )    s+='s';

      cout<<s<<endl;


} 