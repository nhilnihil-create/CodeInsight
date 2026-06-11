#include <bits/stdc++.h>
#define rep(index,num) for(int index=0;index<(int)num;index++)
#define for(index,first,num) for(int index=(int)first;index<(int)num;index++)
using namespace std ;
typedef long long ll;
 
int main(){
    int N,D;cin>>N>>D;

    int count = N/(2*D+1);
    if(N%(2*D+1)==0)cout << count;
    else cout << count+1;
    
      
}