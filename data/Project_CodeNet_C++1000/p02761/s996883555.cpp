#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bug(x) cerr<<#x<<"="<<x<<endl;



int main( ){
  int n,m,pos,num;

  scanf("%d %d",&n,&m);

   vector<int>s(n+1,-1);

  bool ex=0;

  for(int i=0;i<m;i++){

    scanf("%d %d",&pos,&num);
    pos--;

    if((s[pos]>-1&&s[pos]!=num)||(pos+num<1&&n>1)){
        return cout<<-1<<endl,0;
    }
    s[pos]=num;
  }

    cout<<(s[0]==-1?(n>1?1:0):s[0]);
    for(int i=1;i<n;i++)cout<<max(s[i],0);
    cout<<endl;

}