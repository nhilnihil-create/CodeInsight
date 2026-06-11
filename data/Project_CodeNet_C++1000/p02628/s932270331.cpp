#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
   int n,k;
   cin>>n>>k;
   vector<int> v;
   for(int i = 0 ; i< n; i++){
      int z;
      cin>>z;
      v.push_back(z);
   }
   sort(v.begin(),v.end());
   int answer=0;
   for(int i = 0 ; i < k ; i++){
      answer+=v[i];
   }
   cout<<answer<<endl;
   return 0;
}
