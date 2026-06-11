
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;

int main(){

 int n,m,x;
 cin>>n>>m;

  priority_queue<int>Q;
   for(int i=0;i<n;i++){
        cin>>x;
    Q.push(x); }

 long long sum=0;

 while(m--){

    int tops = Q.top();
    Q.pop();
    tops = tops/2;
    Q.push(tops);
 }

 while(!Q.empty()){
   // cout<<Q.top()<<endl;
    sum += Q.top();
    Q.pop();
 }

  cout<<sum<<endl;

 return 0;
}
