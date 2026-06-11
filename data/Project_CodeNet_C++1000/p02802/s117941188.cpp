#include<bits/stdc++.h>
using namespace std;
int main()
{   ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n,m;
    cin>>n>>m;
    vector<bool>vec(n,true);
    vector<int>arr(n, 0);
    int ac=0,pen=0;
    for(int i=0;i<m;i++){
        int p;
        string s;
        cin>>p>>s;
        p--;
       if(vec[p]) {
          if (s=="WA") arr[p]++;
         else {ac++;
              vec[p]=false;
               pen+=arr[p];
             }
       }
    }

  cout<<ac<<" "<<pen<< '\n';

  return 0;
}

