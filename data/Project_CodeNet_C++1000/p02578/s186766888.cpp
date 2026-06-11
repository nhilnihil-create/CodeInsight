#include <bits/stdc++.h>
using  namespace std;
#define ll      long long int
#define pai     pair<int,int>
#define vi      vector<long long int>
#define vb      vector<bool>
#define vm      vector<vector<int> >
#define vd      vector<double>
#define vs      vector<string>
#define vp      vector< pair <string,int> >
#define mpi     map<int,int>
#define mps     map<char,int>
#define sti     stack<int>
#define stc     stack<char>
#define sei     set<int>
#define ses     set<string>
#define multii  multiset<int>
#define forn(i,n)    for (int i = 0; i < n; i++)
#define fork(i,k,n)  for (int i = k; i <= n; i++)
#define forkr(i,k,n) for (int i = k; i >= n; i--)
const int MAX=1e5+1;

 int main()
{
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
ll n;
cin>>n;
vi v(n);
forn(i,n){
cin>>v[i];
}
ll m=v[0];
ll c=0;
for(int i=1;i<n;i++){
if(m>v[i]){
   c+=m-v[i];
}
else{
  m=v[i];
}
}
cout<<c<<endl;
}




