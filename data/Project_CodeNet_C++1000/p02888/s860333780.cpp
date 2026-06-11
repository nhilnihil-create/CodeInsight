#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
   int n,ans=0;
   cin>>n;
   vector<int>a(n);
   //a[0]=0;
   for(int i=0;i<n;i++) cin>>a[i];
   sort(a.begin(),a.end());
   a.push_back(1e9);
   for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i!=j){
                int pos2=lower_bound(a.begin(),a.end(),a[i]+a[j])-a.begin();
                ans+=pos2-j-1;
                //cout<<pos1<<" "<<pos2<<" "<<a[i]<<" "<<a[j]<<" "<<ans<<endl;
            }
        }
   }
   cout<<ans;
}

