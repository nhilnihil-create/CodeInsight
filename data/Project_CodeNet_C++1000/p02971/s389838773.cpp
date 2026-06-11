#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        200001

int32_t main(){
    
    int n;
    cin>>n;
    int arr[n],temp[n];

    set<int>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        temp[i]=arr[i];
    }

    sort(temp,temp+n);
    int mx1=temp[n-1],mx2=temp[n-2];

    // cout<<mx1<<" "<<mx2<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]==mx1)
            cout<<mx2<<endl;
        else
            cout<<mx1<<endl;
    }
    return 0;
}