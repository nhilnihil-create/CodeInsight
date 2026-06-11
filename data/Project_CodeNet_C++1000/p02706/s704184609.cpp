#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin>>n>>m;
  vector<int> hw(m);
  for(int &i:hw)
    cin>>i;
  
  for(int i=0;i<m;i++)
    n-=hw[i];
  
  if(n>=0)
    cout<<n<<endl;
  else
    cout<<-1<<endl;
}
