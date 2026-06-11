#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<int,int> 

int32_t main(){
    int n,p;
    cin>>n>>p;
    string str;
    cin>>str;
    int ans=0;
    if(p==2 || p==5){
        for(int i=0;i<n;i++){
            if((str[i]-'0')%p==0) ans+=i+1;
        }
        cout<<ans<<endl;
        return 0;
    }
    reverse(str.begin(),str.end());
    int arr[n];
    int val=1;
    for(int i=0;i<n;i++){
        arr[n-i-1]=((str[i]-'0')*val)%p;
        val=(val*10)%p;
    }
    
    unordered_map<int,int> cnt;
    int curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum=curr_sum+arr[i];
        cnt[curr_sum%p]++;
    }
    int res=0;
    for(int i=0;i<p;i++){
        res+=(cnt[i]*(cnt[i]-1))/2;
    }
    res+=cnt[0];
    cout<<res<<endl;

    
}