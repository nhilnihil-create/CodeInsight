#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<utility>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int main(){
  int x,y,s;
  while(1){
    cin>>x>>y>>s;
    if(x==0 && y==0 && s==0)break;
    vector<int> good1,good2;
    loop(i,1,s){
      loop(j,1,s){
	int num1=i*(100+x)/100;
	int num2=j*(100+x)/100;
	if((num1+num2)==s){   
	  good1.push_back(i);
	  good2.push_back(j);
	}
      }
    }
    int ans=0;
    int size=good1.size();
    rep(i,size){
      int ans1=good1[i]*(100+y)/100;
      int ans2=good2[i]*(100+y)/100;
      ans=max(ans,ans1+ans2);
    }
    cout<<ans<<endl;
  }
  return 0;
}