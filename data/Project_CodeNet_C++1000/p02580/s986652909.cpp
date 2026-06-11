#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   int h,w,m;
   cin >> h >> w >> m;
   vector<int> b_h(m), b_w(m);
   set<pair<int,int>> s;
   map<int, int> m_h,m_w;
   for(int i=0; i<m; i++){
       int a,b;
       cin >> a >> b;
       b_h.at(i)=a;
       b_w.at(i)=b;
       m_h[a]++;
       m_w[b]++;
       pair<int, int> pa = make_pair(a,b);
       s.insert(pa);
   }
   int p=0,q=0;
   for(auto k:m_h){
       p=max(p,k.second);
   }
   for(auto k:m_w){
       q=max(q,k.second);
   }
   vector<int> max_h,max_w;
   for(auto k:m_h){
       if(k.second == p) max_h.push_back(k.first);
   }
   for(auto k:m_w){
       if(k.second == q) max_w.push_back(k.first);
   }
   for(int i=0; i<max_h.size(); i++){
       for(int j=0; j<max_w.size(); j++){
           int ans_h,ans_w;
           ans_h = max_h.at(i);
           ans_w = max_w.at(j);
           pair<int, int> check = make_pair(ans_h,ans_w);
           if(!s.count(check)){
               cout << p+q  << endl;
               return 0;
           }
       }
   }
   cout << p+q-1 << endl;
}