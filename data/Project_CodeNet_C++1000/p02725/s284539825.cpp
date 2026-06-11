#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int k,n;
    cin>>k>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    vector<int> ans;
    for(int i=1;i<n;i++){
        ans.push_back(a[i]-a[i-1]);
    }
    int first=a[0];
    int last=a[a.size()-1];
    int left=k-last+first;
    // cout<<first<<" "<<last<<" "<<left;
    ans.push_back(left);
    sort(ans.begin(),ans.end());
    ll sum=0;
    // cout<<ans.size()<<endl;
    for(int i=0;i<ans.size()-1;i++){
        sum+=ans[i];
        // cout<<ans[i]<<" ";
    }
    cout<<sum<<endl;

}