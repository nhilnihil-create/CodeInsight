#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
   int x, y, a, b, c;
   cin>>x>>y>>a>>b>>c;
   vector<int> p(a), q(b), r(c);
   rep(i, a) cin>>p[i];
   rep(i, b) cin>>q[i];
   rep(i, c) cin>>r[i];


   priority_queue<int, vector<int>, greater<int>> aet;
   sort(p.rbegin(), p.rend());
   rep(i, x) aet.push(p[i]);
   sort(q.rbegin(), q.rend());
   rep(i, y) aet.push(q[i]);

   sort(r.rbegin(), r.rend());
   queue<int> noc;
   for(int e : r) noc.push(e);

   while(!noc.empty()){
      if(noc.front() > aet.top()){
         aet.pop();
         aet.push(noc.front());
         noc.pop();
      }
      else break;
   }

   ll s=0;
   while(!aet.empty()){
      s+=aet.top();
      aet.pop();
   }

   cout << s << endl;
   return 0;
}
