# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int n,arr[25],bil,sum,c[25];
int x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        sum+=x;
    }
    for(int i=1;i<n;i++){
        cin>>c[i];
    }
    for(int i=1;i<n;i++){
        if(arr[i+1]==arr[i]+1) sum+=c[arr[i]];
    
        
    }
    cout<<sum<<endl;
    
}