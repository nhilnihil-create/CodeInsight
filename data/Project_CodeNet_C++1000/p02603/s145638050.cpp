    #include<bits/stdc++.h>
    using namespace std;
    #define lint long long
    #define inf 100000000000000000
    #define mod 1000000007
    #define MAX 200005
    #define pb push_back
    #define vit vector<int>::iterator
  
    lint A[MAX];
    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        lint n,ans,ns,ne;
        cin>>n;
        for(lint i=1;i<=n;i++) cin>>A[i];
        ans=1000;
        ns=ans/A[1];
        ne=ans%A[1];
        for(lint i=2;i<=n;i++){
            if(A[i]>A[i-1]){
                ans=max(ans,ns*A[i]+ne);
            }
            else{
                ns=ans/A[i];
                ne=ans%A[i];
            }
        }
        cout<<ans;
        return 0;
    }