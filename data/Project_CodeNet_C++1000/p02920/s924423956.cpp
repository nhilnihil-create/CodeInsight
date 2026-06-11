        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD =  998244353;
const int  Inv2 = (MOD+1)/2;
stack<int> que;
     signed main(){
int n,a;
cin>>n;
multiset<int> s;
vector<int> x;
for(int i=0;i<(1<<n);i++){
   cin>>a;
   s.insert(-1*a);
}
auto it=s.begin();
x.push_back(*it);
s.erase(it++);
for(int i=0;i<n;i++){
   it=s.begin();
    sort(x.begin(),x.end());
   for(int j=0;j<(1<<i);j++){
      //cerr<<*it<<' '<<x[j]<<' ';
      while(it!=s.end()&&(*it)<=x[j])it++;
      if(it==s.end()){
         cout<<"No";
         return 0;
      }
      x.push_back(*it);
      s.erase(it++);
   }
  
}
cout<<"Yes";
      }

        
