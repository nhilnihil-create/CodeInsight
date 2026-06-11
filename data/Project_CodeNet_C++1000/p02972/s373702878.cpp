#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+100;
int a[N],b[N];
vector<int>ve;
int main()
{
     ios::sync_with_stdio(0);cin.tie(0);
     int n;cin>>n;
     for(int i=1;i<=n;i++) cin>>a[i];
     for(int i=n;i>=1;i--)
     {
         if((b[i]&1)^a[i]){
              ve.push_back(i);
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                if(j*j==i) b[j]++;
                else  b[j]++,b[i/j]++;
            }
        }
        }
     }
     cout<<ve.size()<<endl;
     for(auto v:ve){
        cout<<v<<" ";
     }
    return 0;
}
