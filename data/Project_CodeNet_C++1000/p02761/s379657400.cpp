#include <iostream>
#include<set>
#define INF 1e8
using namespace std;
int main(void){
    // Your code here!
#define ar array

int ar[3]{-1,-1,-1};
int n,m;
cin >>n>>m;

for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    if((a==1 && b==0 && n!=1) || (ar[a-1]!=-1 && ar[a-1]!=b)){
          cout<<-1;
        return 0;
    }
    ar[a-1]=b;
}
    if(ar[0]==-1 && n==1)
    {
        cout<<0;
        return 0;
    }
        

    if(ar[0]==-1)
            ar[0]=1;
    if(ar[1]==-1)
        ar[1]=0;
      if(ar[2]==-1)
        ar[2]=0;
        
if(n==1)
cout<<ar[0];
else if(n==2)
cout<<ar[0]*10+ar[1];
else
cout<<ar[0]*100+ar[1]*10+ar[2];
}
