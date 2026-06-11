#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define ll long long 
#define mod 1000000007 
#define mod2 998244353
void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}



int main() {
   fast();
   priority_queue<int> pq;
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++){
    int l;
    cin>>l;
    pq.push(l);
   }
   while(m--){
    int q=pq.top();
    pq.pop();
    pq.push(q/2);
   }
   long long sum=0;
   while(n--){
      int q=pq.top();
      sum+=q;
      pq.pop();
   }
   cout<<sum<<"\n";


}
