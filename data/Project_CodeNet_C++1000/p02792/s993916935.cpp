#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define pb push_back


pii topdown(int x){
  int top=0;
  for (int i=1;i<=100000;i*=10){
    int tmp;
    tmp=x/i;
    if (tmp==0){
      break;
    }
    top=tmp;
  }
  
  auto ans=make_pair(top,x%10);
  return ans;
}





int main(){
  
  int n;
  cin>>n;

  vector<vector<int>> count(10,vector<int>(10,0));
  

  for (int i=1;i<=n;i++){
    int a=topdown(i).first;
    int b=topdown(i).second;
    count.at(a).at(b)++;
  }
  
  int answer=0;
  
  for (int i=1;i<=9;i++){
    for (int j=1;j<=9;j++){
      answer+=count.at(i).at(j)*count.at(j).at(i);
    }
  }
  
  cout<<answer<<endl;
  

}


















