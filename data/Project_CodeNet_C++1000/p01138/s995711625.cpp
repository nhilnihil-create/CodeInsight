#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
  while(1){
    int n;
    string a[10001],b;
    priority_queue<string,vector<string>,greater<string> > c;
    cin>>n;
    if(n==0)break;
    for(int i=0;i<n;i++){
      cin>>a[i]>>b;
      c.push(b);
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++){
      if(a[i]>=c.top()){
	c.pop();
      }else cnt++;
    }
    cout<<cnt<<endl;
  }
  return 0;
}